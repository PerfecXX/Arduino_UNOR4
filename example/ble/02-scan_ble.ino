#include <ArduinoBLE.h>

void setup() {
  Serial.begin(9600);

  while (!Serial);

  if (!BLE.begin()) {
    Serial.println("BLE Initialization Failed!");
    while (1);
  }

  Serial.println("Arduino UNO R4 WiFi");
  Serial.println("BLE Scanner Ready");
}

void loop() {
  Serial.println("\nScanning...");

  BLE.scan();

  unsigned long startTime = millis();

  while (millis() - startTime < 5000) {
    BLEDevice device = BLE.available();

    if (device) {
      Serial.print("Name: ");
      Serial.println(device.localName());

      Serial.print("Address: ");
      Serial.println(device.address());

      Serial.print("RSSI: ");
      Serial.print(device.rssi());
      Serial.println(" dBm");

      Serial.println("-------------------");
    }
  }

  BLE.stopScan();

  delay(2000);
}
