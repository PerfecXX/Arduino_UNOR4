#define RELAY_PIN 13
#define BTN_PIN 7
#define WATER_LV_SEN A0

int btn_state;
bool manual_control = false;
unsigned long manual_control_start = 0;
const unsigned long manual_control_timeout = 10000;

#include "thingProperties.h"

void setup() {
  pinMode(RELAY_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT);
  
  Serial.begin(9600);
  delay(1500);
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  water_level = analogRead(WATER_LV_SEN);
  btn_state = digitalRead(BTN_PIN);
  
  if (manual_control && millis() - manual_control_start >= manual_control_timeout) {
    manual_control = false;
  }

  if (manual_control && btn_state == 1) {
    manual_control = false;
  }
  
  if (!manual_control) {
    if (btn_state == 1 || scheduler.isActive()) {
      relay_state = true;
    } else {
      relay_state = false;
    }
    
    digitalWrite(RELAY_PIN, relay_state ? HIGH : LOW);
  }
}

void onRelayStateChange() {
  manual_control = true; 
  manual_control_start = millis();
  digitalWrite(RELAY_PIN, relay_state ? HIGH : LOW);
}

void onSchedulerChange() {
  if (!manual_control) {
    relay_state = scheduler.isActive();
    digitalWrite(RELAY_PIN, relay_state ? HIGH : LOW);
  }
}

void onWaterLevelChange(){}
