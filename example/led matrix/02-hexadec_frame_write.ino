#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

unsigned long frame[] = {
  0x3184a444,
  0x42081100,
  0xa0040000
};

unsigned long clear_frame[] = {
  0x00000000,
  0x00000000,
  0x00000000
};

void setup() {
  Serial.begin(115200);
  matrix.begin();
}

void loop() {
  matrix.loadFrame(frame);
  delay(500);
  matrix.loadFrame(clear_frame);
  delay(500);
}
