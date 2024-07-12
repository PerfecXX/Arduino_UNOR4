/*
Author : Teeraphat Kullanankanjana
Version : 1.0
Date : 12/07/2024
Full Schematic : https://www.tinkercad.com/things/jrRtU52r3T7-arduino-uno-r3-blink-led?sharecode=iOjtYHlZs_cjhLZVU2TRlMjGgTfz3ejqEZajCwcj7TE
*/

#define LED_PIN 2

void setup() {
  // initialize digital pin 2 as an output.
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  digitalWrite(LED_PIN, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);                      // wait for a second
  digitalWrite(LED_PIN, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);                      // wait for a second
}
