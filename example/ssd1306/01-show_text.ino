#include <Adafruit_SSD1306.h>
#include <Wire.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setup() {

  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.print(F("Hello, world!"));
  display.display();
}

void loop() {

}
