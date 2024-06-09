#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

unsigned long my_frame[] = {
  0x3184a444,
  0x42081100,
  0xa0040000
};

void setup() {
  matrix.begin();
  matrix.loadFrame(my_frame);
}

void loop() {
}
