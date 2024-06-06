#define I2C_ADDRESS 0x3F
#define LCD_HEIGHT 2
#define LCD_WIDTH 16

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(I2C_ADDRESS, LCD_WIDTH, LCD_HEIGHT);

void setup() {
  
  lcd.init();                      
  lcd.backlight();

  lcd.setCursor(0, 0);                 
  lcd.print("Hello World");
  
  lcd.setCursor(0, 1);
  lcd.print("PerfecXX");      
}

void loop() {
  
}    
