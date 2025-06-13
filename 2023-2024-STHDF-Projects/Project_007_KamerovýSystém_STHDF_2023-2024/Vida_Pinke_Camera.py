import io
import picamera
import cv2
import numpy
import picamera.array
import pigpio

def main():
    SERVO = 18
    VPRAVO_PW = 1350
    STOP_PW = 1500
    VLAVO_PW = 1600
     
    pwm = pigpio.pi()
    pwm.set_servo_pulsewidth(SERVO, STOP_PW)
    
    face_cascade = cv2.CascadeClassifier('/home/admin/Face Recognition/haarcascade_frontalface_default.xml')
    eye_cascade = cv2.CascadeClassifier('/home/admin/Face Recognition/haarcascade_eye.xml')
 
    with picamera.PiCamera() as camera:
        camera.resolution = (320, 240)
        camera.framerate = 15
        camera.rotation = 180
 
        with picamera.array.PiRGBArray(camera, size=(320, 240)) as stream:
            for frame in camera.capture_continuous(stream, format='bgr', use_video_port=True):
                image = frame.array
 
                gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
 
                faces = face_cascade.detectMultiScale(gray, 1.1, 5)
 
                for (x, y, w, h) in faces:
                    cv2.rectangle(image, (x, y), (x+w, y+h), (255, 255, 0), 2)
 
                    roi_gray = gray[y:y+h, x:x+w]
                    roi_color = image[y:y+h, x:x+w]
                    
                    eyes = eye_cascade.detectMultiScale(roi_gray, 1.03, 5, minSize=(30,30))
                    for (ex, ey, ew, eh) in eyes:
                        cv2.rectangle(roi_color, (ex, ey), (ex+ew, ey+eh), (0, 255, 0), 2)
 
                display_frame = cv2.resize(image, (640, 480))
 
                cv2.imshow('Face and Eye Detection', display_frame)
 
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
                    break;
 
        cv2.destroyAllWindows()
 
if __name__ == '__main__':
    main()
