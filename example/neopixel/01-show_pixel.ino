#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN 10          
#define NEOPIXEL_NUM 3   

Adafruit_NeoPixel pixels(NEOPIXEL_NUM, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  pixels.begin();
}

void loop() {
  
  pixels.clear();                        
  pixels.setPixelColor(0, pixels.Color(255, 0, 0)); 
  pixels.show();                          
  delay(1000);                            
  
  
  pixels.clear();                         
  pixels.setPixelColor(1, pixels.Color(0, 255, 0)); 
  pixels.show();                        
  delay(1000);                          

 
  pixels.clear();                         
  pixels.setPixelColor(2, pixels.Color(0, 0, 255)); 
  pixels.show();                          
  delay(1000);                            
}
