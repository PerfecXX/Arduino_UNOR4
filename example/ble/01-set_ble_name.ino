#include <ArduinoBLE.h>

const char* BLE_NAME = "Arduino UNO R4 WIFI";

void setup() {
  Serial.begin(9600);

  if (!BLE.begin()) {
    Serial.println("BLE initialization failed!");
    while (1);
  }

  BLE.setLocalName(BLE_NAME);
  BLE.setDeviceName(BLE_NAME);

  BLE.advertise();

  Serial.print("BLE Device Name: ");
  Serial.println(BLE_NAME);
}

void loop() {
  BLE.poll();
}
