#define SERVO_PIN 10

#include <Servo.h>

Servo myservo;

void setup() {
  myservo.attach(SERVO_PIN);
  myservo.write(0);
}

void loop() {
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
}
