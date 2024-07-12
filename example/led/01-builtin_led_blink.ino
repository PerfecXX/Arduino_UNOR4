/*
Author : 
Version : 1.0
Date : 12/07/2024
Full Schematic : https://www.tinkercad.com/things/jsNyNxq8lcs-arduino-uno-r3-builtin-led?sharecode=0hEjEWMKYy9BL7d-o1PwFixF_IR-AufdBLhPSgFasFI
*/

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_BUILTIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
