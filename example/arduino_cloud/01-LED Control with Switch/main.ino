#include "thingProperties.h"

void setup() {
  
  pinMode(LED_BUILTIN,OUTPUT);
  
  Serial.begin(9600);
  
  delay(1500); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
}

void onLedStateChange()  {
  if (led_state == true)
  {
    digitalWrite(LED_BUILTIN,HIGH);
  }
  else{
    digitalWrite(LED_BUILTIN,LOW);
  }
}
