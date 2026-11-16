
#include <ArduinoBLE.h>

// BLE Configuration
const char* BLE_NAME = "Arduino UNO R4 WIFI";

const char* UART_SERVICE_UUID = "6E400001-B5A3-F393-E0A9-E50E24DCCA9E";
const char* UART_RX_UUID = "6E400002-B5A3-F393-E0A9-E50E24DCCA9E";
const char* UART_TX_UUID = "6E400003-B5A3-F393-E0A9-E50E24DCCA9E";

// Buffer Configuration
const int RX_BUFFER_SIZE = 200;
const int TX_BUFFER_SIZE = 512;
const int BLE_PACKET_SIZE = 200;

// BLE Service & Characteristics
BLEService uartService(UART_SERVICE_UUID);
BLECharacteristic RX(UART_RX_UUID, BLEWrite | BLEWriteWithoutResponse, RX_BUFFER_SIZE);
BLECharacteristic TX(UART_TX_UUID, BLENotify, BLE_PACKET_SIZE);

// TX Ring Buffer
uint8_t txBuffer[TX_BUFFER_SIZE];
int txHead = 0;
int txTail = 0;
int txCount = 0;

unsigned long lastInput = 0;
unsigned long lastSend = 0;

const unsigned long COLLECT_INTERVAL = 100;
const unsigned long SEND_INTERVAL = 10;

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

  // Receive from Mobile
  if (RX.written()) {
    int len = RX.valueLength();

    uint8_t buffer[RX_BUFFER_SIZE];

    if (len > RX_BUFFER_SIZE) {
      len = RX_BUFFER_SIZE;
    }

    RX.readValue(buffer, len);
    Serial.write(buffer, len);
  }

  // Read Serial Monitor into Ring Buffer
  while (Serial.available() && txCount < TX_BUFFER_SIZE) {
    txBuffer[txHead] = Serial.read();

    txHead = (txHead + 1) % TX_BUFFER_SIZE;
    txCount++;

    lastInput = millis();
  }

  // Send BLE Notification
  if (txCount > 0 &&
      txCount >= BLE_PACKET_SIZE &&
      millis() - lastSend >= SEND_INTERVAL &&
      BLE.connected() &&
      TX.subscribed()) {

    uint8_t packet[BLE_PACKET_SIZE];

    for (int i = 0; i < BLE_PACKET_SIZE; i++) {
      packet[i] = txBuffer[txTail];
      txTail = (txTail + 1) % TX_BUFFER_SIZE;
    }

    if (TX.writeValue(packet, BLE_PACKET_SIZE)) {
      txCount -= BLE_PACKET_SIZE;
      lastSend = millis();
    }
  }

  // Send remaining data after collection interval
  else if (txCount > 0 &&
           millis() - lastInput >= COLLECT_INTERVAL &&
           millis() - lastSend >= SEND_INTERVAL &&
           BLE.connected() &&
           TX.subscribed()) {

    int len = min(txCount, BLE_PACKET_SIZE);
    uint8_t packet[BLE_PACKET_SIZE];

    for (int i = 0; i < len; i++) {
      packet[i] = txBuffer[txTail];
      txTail = (txTail + 1) % TX_BUFFER_SIZE;
    }

    if (TX.writeValue(packet, len)) {
      txCount -= len;
      lastSend = millis();
    }
  }

  BLE.poll();
}
