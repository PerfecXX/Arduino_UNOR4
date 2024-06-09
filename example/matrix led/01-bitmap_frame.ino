#define COL_SIZE 12
#define ROW_SIZE 8

#include "Arduino_LED_Matrix.h"

ArduinoLEDMatrix matrix;

byte my_frame[ROW_SIZE][COL_SIZE] = {
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
  { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
};

void setup() {
  matrix.begin();

  //      ROW Column
  my_frame[0][0] = 1;
  my_frame[0][1] = 1;
  my_frame[1][0] = 1;
  my_frame[1][1] = 1;
  matrix.renderBitmap(my_frame, ROW_SIZE, COL_SIZE);
}

void loop() {
}
