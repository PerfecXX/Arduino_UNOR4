#define POT_PIN A0
#define SERVO_PIN 10

#include <Servo.h>
Servo myservo;

int pot_val;
int pot_percentage;

void setup() {
  myservo.attach(SERVO_PIN);
  myservo.write(0);
  Serial.begin(9600);
}

void loop() {
  pot_val = analogRead(POT_PIN);
  pot_percentage = map(pot_val, 0, 1023, 0, 180);

  Serial.print("Potentiometer:");
  Serial.println(pot_val);

  Serial.print("PotPercentage:");
  Serial.println(pot_percentage);
  
  myservo.write(pot_percentage);
  delay(100);
}

