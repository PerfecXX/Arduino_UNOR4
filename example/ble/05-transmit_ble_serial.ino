#include <ArduinoBLE.h>

// BLE Configuration
const char* BLE_NAME = "Arduino UNO R4 WIFI";

const char* UART_SERVICE_UUID = "6E400001-B5A3-F393-E0A9-E50E24DCCA9E";
const char* UART_TX_UUID = "6E400003-B5A3-F393-E0A9-E50E24DCCA9E";

// Buffer Configuration
const int TX_BUFFER_SIZE = 200;

// BLE Service & Characteristic
BLEService uartService(UART_SERVICE_UUID);
BLECharacteristic TX(UART_TX_UUID, BLENotify, TX_BUFFER_SIZE);

// Serial Buffer
char serialBuffer[TX_BUFFER_SIZE + 1];
int serialIndex = 0;

void setup() {
  Serial.begin(9600);

  if (!BLE.begin()) {
    Serial.println("BLE Initialization Failed!");
    while (1);
  }

  BLE.setLocalName(BLE_NAME);
  BLE.setDeviceName(BLE_NAME);

  uartService.addCharacteristic(TX);

  BLE.setAdvertisedService(uartService);
  BLE.addService(uartService);

  BLE.advertise();

  Serial.println("BLE Transmitter Ready!");
  Serial.println(BLE_NAME);
}

void loop() {
  BLE.poll();

  while (Serial.available()) {
    char c = Serial.read();

    if (c == '\n') {
      if (serialIndex > 0) {
        if (BLE.connected() && TX.subscribed()) {
          TX.writeValue(
            (const unsigned char*)serialBuffer,
            serialIndex
          );
        }

        serialIndex = 0;
      }
    }
    else if (c != '\r') {
      if (serialIndex < TX_BUFFER_SIZE) {
        serialBuffer[serialIndex++] = c;
      }
    }
  }
}
