/* 
  Arduino IoT Cloud Variables description
  The following variables are automatically generated and updated when changes are made to the Thing

  int selector;
*/

#define RED_LED 8
#define BLUE_LED 9
#define GREEN_LED 10

#include "thingProperties.h"

void setup() {
  pinMode(RED_LED,OUTPUT);
  pinMode(BLUE_LED,OUTPUT);
  pinMode(GREEN_LED,OUTPUT);
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

void onSelectorChange()  {
  if (selector == 0){
    digitalWrite(RED_LED,HIGH);
  }
  else if (selector == 1){
    digitalWrite(BLUE_LED,HIGH);
  }
  else if (selector == 2){
    digitalWrite(GREEN_LED,HIGH);
  }
  else if (selector == 3){
    digitalWrite(RED_LED,LOW);
  }
  else if (selector == 4){
    digitalWrite(BLUE_LED,LOW);
  }
  else if (selector == 5){
    digitalWrite(GREEN_LED,LOW);
  }
  else if (selector == 6){
    digitalWrite(RED_LED,HIGH);
    digitalWrite(BLUE_LED,HIGH);
    digitalWrite(GREEN_LED,HIGH);
  }
  else if (selector == 7){
    digitalWrite(RED_LED,LOW);
    digitalWrite(BLUE_LED,LOW);
    digitalWrite(GREEN_LED,LOW);
  }
}
