/*
Generate hexdecimal metrix with https://ledmatrix-editor.arduino.cc/
*/

#define BTN_PIN 7

#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

unsigned long digits[10][4] = {
  {0xf010810,0x81081081,0x80f0000,66},  //0
  {0x200600a,0x200200,0x200f0000,66},   //1
  {0x1f800800,0x81f81001,0x1f8000,66},  //2
  {0x1f800800,0x81f80080,0x81f8000,66}, //3
  {0x11011011,0x1f00100,0x10010000,66}, //4
  {0x1f010010,0x1f00100,0x101f0000,66}, //5
  {0x1f010010,0x1f01101,0x101f0000,66}, //6
  {0x1f011011,0x100100,0x10010000,66},  //7
  {0x1f810810,0x81f81081,0x81f8000,66}, //8
  {0xf808808,0x80f80080,0x80f8000,66}  //9
};

int number = 0;
bool lastButtonState = LOW;

void setup() {
  matrix.begin();
  pinMode(BTN_PIN, INPUT);
  matrix.loadFrame(digits[number]); // show first digit 
}

void loop() {
  bool buttonState = digitalRead(BTN_PIN);
  
  // Check for a button press
  if (buttonState == LOW && lastButtonState == HIGH) {
    number = (number + 1) % 10;
    matrix.loadFrame(digits[number]);
    delay(200);  // Debounce delay
  }

  lastButtonState = buttonState;
}
