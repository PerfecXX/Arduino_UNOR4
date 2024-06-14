/* 
  Arduino IoT Cloud Variables description
  The following variables are automatically generated and updated when changes are made to the Thing

  bool led_state;
*/

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
