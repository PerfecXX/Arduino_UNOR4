#include "ArduinoGraphics.h"
#include "Arduino_LED_Matrix.h"

#define RED_COLOR 0xFFFFFFFF
#define FONT_SIZE Font_5x7

//      Speed (milliseconds)
#define SCROLL_SPD 500
//      Direction (NO_SCROLL,SCROLL_LEFT,SCROLL_RIGHT,SCROLL_UP,SCROLL_DOWN) 
#define SCROLL_DIR SCROLL_LEFT 

ArduinoLEDMatrix matrix;

char text[] = "HEY";

void setup() {
  matrix.begin();
}

void loop() {
  matrix.beginDraw();
  //            color
  matrix.stroke(RED_COLOR);
  //                    speed
  matrix.textScrollSpeed(SCROLL_SPD);

  //              font size
  matrix.textFont(FONT_SIZE);
  //               x  y  color
  matrix.beginText(0, 1, RED_COLOR);
  //             text
  matrix.println(text);
  //             direction 
  matrix.endText(SCROLL_DIR);

  matrix.endDraw();
}
