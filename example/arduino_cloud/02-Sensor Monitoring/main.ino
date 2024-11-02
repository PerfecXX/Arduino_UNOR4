#define LDR_PIN A1
#define DHTPIN 8      
#define DHTTYPE DHT11 

#include "thingProperties.h"
#include <DHT.h>

DHT dht(DHTPIN, DHTTYPE);
int ldr_val;

void setup() {
  Serial.begin(9600);
  dht.begin();
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  
  humidity = dht.readHumidity(); 
  temperature = dht.readTemperature(); 
  
  ldr_val = analogRead(LDR_PIN);
  light_percentage = map(ldr_val, 1023, 0, 100, 0);
  delay(100);
}

void onLightPercentageChange()  {}
void onTemperatureChange()  {}
void onHumidityChange()  {}
