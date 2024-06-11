#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

#define RED_COLOR 0xFFFFFFFF
#define FONT_SIZE Font_4x6
#define SCOLL_DIR NO_SCROLL

ArduinoLEDMatrix matrix;

char text[] = "HEY";

void setup() {
  matrix.begin();

  matrix.beginDraw();
  //            color
  matrix.stroke(RED_COLOR);
  //              font size
  matrix.textFont(FONT_SIZE);
  //               x  y  color
  matrix.beginText(0, 1, RED_COLOR);
  //             text
  matrix.println(text);
  //             direction 
  matrix.endText(SCOLL_DIR);

  matrix.endDraw();
}

void loop() {
}
