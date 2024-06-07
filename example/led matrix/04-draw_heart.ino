#define MATRIX_WIDTH 12
#define MATRIX_HEIGHT 8

#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

byte matrix_frame[MATRIX_HEIGHT][MATRIX_WIDTH] = {
  { 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
  { 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0 },
  { 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0 },
  { 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0 },
  { 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void setup() {
  Serial.begin(9600);
  matrix.begin();

  matrix.renderBitmap(matrix_frame, MATRIX_HEIGHT, MATRIX_WIDTH);
}

void loop() {
}
