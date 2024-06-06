/*
------------------------------
LCD I2C PIN    Arduino UNO R4 PIN
------------------------------
GND      ->      GND
VCC      ->      5V
SDA      ->      A4
SCL      ->      A5
*/

#include <Wire.h>  // Include the Wire library for I2C communication

void setup() {
  Serial.begin(9600);  // Start serial communication at 9600 baud

  // Wait for the serial port to connect. Needed for native USB port only
  while (!Serial) {
    // Do nothing until the serial port is ready
  }

  // Print initial messages to the Serial Monitor
  Serial.println();
  Serial.println("I2C scanner. Scanning ...");

  byte count = 0;  // Initialize a counter to count the number of I2C devices found

  Wire.begin();  // Initialize the Wire library and join the I2C bus as a master

  // Loop through all possible I2C addresses from 8 to 119
  for (byte i = 8; i < 120; i++) {
    Wire.beginTransmission(i);  // Begin an I2C transmission to the device at address 'i'
    if (Wire.endTransmission() == 0) {  // If a device responds (endTransmission returns 0)
      Serial.print("Found address: ");  // Print the address of the found device
      Serial.print(i, DEC);  // Print the address in decimal format
      Serial.print(" (0x");  // Print the opening bracket for hexadecimal format
      Serial.print(i, HEX);  // Print the address in hexadecimal format
      Serial.println(")");  // Print the closing bracket and move to the next line
      count++;  // Increment the device count
      delay(1);  // Brief pause between scans to avoid bus contention
    }
  }

  // Print completion messages to the Serial Monitor
  Serial.println("Done.");
  Serial.print("Found ");
  Serial.print(count, DEC);  // Print the number of devices found in decimal format
  Serial.println(" device(s).");  // Print the closing message with the number of devices found
}

void loop() {
  // The loop function is intentionally left empty because we only need to scan once in the setup function
}
