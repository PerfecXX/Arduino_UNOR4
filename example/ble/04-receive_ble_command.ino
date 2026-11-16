#include <ArduinoBLE.h>

// BLE Configuration
const char* BLE_NAME = "Arduino UNO R4 WIFI";

const char* UART_SERVICE_UUID = "6E400001-B5A3-F393-E0A9-E50E24DCCA9E";
const char* UART_RX_UUID = "6E400002-B5A3-F393-E0A9-E50E24DCCA9E";
const char* UART_TX_UUID = "6E400003-B5A3-F393-E0A9-E50E24DCCA9E";

// Buffer Configuration
const int RX_BUFFER_SIZE = 200;
const int TX_BUFFER_SIZE = 200;

// BLE Service & Characteristics
BLEService uartService(UART_SERVICE_UUID);
BLECharacteristic RX(UART_RX_UUID,BLEWrite | BLEWriteWithoutResponse,RX_BUFFER_SIZE);
BLECharacteristic TX(UART_TX_UUID,BLENotify,TX_BUFFER_SIZE);

void setup() {
  Serial.begin(9600);

  if (!BLE.begin()) {
    Serial.println("BLE Initialization Failed!");
    while (1);
  }

  BLE.setLocalName(BLE_NAME);
  BLE.setDeviceName(BLE_NAME);

  uartService.addCharacteristic(RX);
  uartService.addCharacteristic(TX);

  BLE.setAdvertisedService(uartService);
  BLE.addService(uartService);

  BLE.advertise();

  Serial.println("BLE Ready!");
  Serial.println(BLE_NAME);
}


void loop() {
  BLE.poll();

  if (RX.written()) {
    int len = RX.valueLength();

    char buffer[RX_BUFFER_SIZE + 1] = {0};

    if (len > RX_BUFFER_SIZE) {
      len = RX_BUFFER_SIZE;
    }

    RX.readValue((unsigned char*)buffer, len);

    Serial.print("Received: ");
    Serial.println(buffer);

    // Check Command
    if (strcmp(buffer, "Hello") == 0) {

      const char* response = "Hi";

      TX.writeValue(
        (const unsigned char*)response,
        strlen(response)
      );
    }
  }
}

