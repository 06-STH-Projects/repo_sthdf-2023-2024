import io
import picamera
import cv2
import numpy
import picamera.array
import pigpio
import imutils


def main():
    SERVO = 18
    VPRAVO_PW = 1350
    STOP_PW = 1500
    VLAVO_PW = 1600

    pwm = pigpio.pi()
    pwm.set_servo_pulsewidth(SERVO, STOP_PW)

    with picamera.PiCamera() as camera:
        camera.resolution = (320, 240)
        camera.framerate = 15
        camera.rotation = 180
        avgPrevious = None

        with picamera.array.PiRGBArray(camera, size=(320, 240)) as stream:
            for frame in camera.capture_continuous(stream, format='bgr', use_video_port=True):
                image = frame.array

                gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
                gray = cv2.GaussianBlur(gray, (21, 21), 0)

                if avgPrevious is None:
                    print("Starting up ...")
                    avgPrevious = gray.copy().astype("float")
                    stream.truncate(0)
                    continue

                cv2.accumulateWeighted(gray, avgPrevious, 0.5)
                frameDelta = cv2.absdiff(gray, cv2.convertScaleAbs(avgPrevious))

                thresh = cv2.threshold(frameDelta, 5, 255,
                                       cv2.THRESH_BINARY)[1]
                thresh = cv2.dilate(thresh, None, iterations=2)
                cnts = cv2.findContours(thresh.copy(), cv2.RETR_EXTERNAL,
                                        cv2.CHAIN_APPROX_SIMPLE)
                
                cnts = imutils.grab_contours(cnts)
                
                for c in cnts:
                        if cv2.contourArea(c) < 5000:
                            continue
                        (x, y, w, h) = cv2.boundingRect(c)
                        cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)
                
                display_frame = cv2.resize(image, (640, 480))

                cv2.imshow('Security Feed', display_frame)

                stream.truncate(0)

                pressedKey = cv2.waitKey(1) & 0xFF

                if pressedKey == ord('a'):
                    pwm.set_servo_pulsewidth(SERVO, VLAVO_PW)

                elif pressedKey == ord('d'):
                    pwm.set_servo_pulsewidth(SERVO, VPRAVO_PW)

                elif pressedKey == ord('s'):
                    pwm.set_servo_pulsewidth(SERVO, STOP_PW)

                elif pressedKey == ord('q'):
                    pwm.set_servo_pulsewidth(SERVO, STOP_PW)
                    break

        cv2.destroyAllWindows()


if __name__ == '__main__':
    main()
