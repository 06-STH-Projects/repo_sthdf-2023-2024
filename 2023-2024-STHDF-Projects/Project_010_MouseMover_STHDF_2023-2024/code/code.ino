#include <Servo.h>

Servo myservo;

int pos = 0;

long randomAngle;
long randomSpeed;

void setup() {
  myservo.attach(2);
  randomSeed( analogRead(A0) );
}

void loop() {
  randomAngle = random(0, 181);
  randomSpeed = random(2, 20);
  for (pos = 0; pos <= randomAngle; pos += 1) {
    myservo.write(pos);
    delay(randomSpeed);
  }
  delay(random(500, 2000));
  for (pos = randomAngle; pos >= 0; pos -= 1) { 
    myservo.write(pos);
    delay(randomSpeed);
  }
}