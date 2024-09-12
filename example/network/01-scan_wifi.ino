#include <WiFi.h> 

int numNetworks;

void setup() {
  
  Serial.begin(9600);

  Serial.println("Scanning for networks...");
  numNetworks = WiFi.scanNetworks(); // Scan for networks

  Serial.print("Number of networks found: ");
  Serial.println(numNetworks);

  for (int i = 0; i < numNetworks; i++) {
    Serial.print("Network #");
    Serial.print(i + 1); 
    Serial.print(": ");
    Serial.print("SSID: ");
    Serial.print(WiFi.SSID(i)); 
    Serial.print(" | Signal Strength (dBm): ");
    Serial.print(WiFi.RSSI(i)); 
    Serial.print(" | Encryption Type: ");
    Serial.print(WiFi.encryptionType(i)); 
    Serial.print(" | Channel: ");
    Serial.print(WiFi.channel(i)); 
    Serial.println(); 
  }
}

void loop() {
}

