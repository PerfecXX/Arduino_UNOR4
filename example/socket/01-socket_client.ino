/*
Author      : Teeraphat Kullanankanjana
Version     : 1.0
Date        : 18/03/2025
Description : Connects to a specified WiFi network, establishes a TCP connection to a specified IP and port,
              and sends/receives data through the socket.
Copyright (C) 2025 Teeraphat Kullanankanjana. All rights reserved.
*/

// Include WiFi library for Arduino UNO R4 WiFi
#include <WiFiS3.h>  

// Replace with your WiFi credentials
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

// Server details (IP and port)
const char* server_ip = "192.168.1.105";
const int server_port = 1102;

// Create a WiFi client object
WiFiClient client;  

void setup() {
  // Start serial communication
  Serial.begin(9600);
  // Wait for serial monitor to open  
  while (!Serial)  
    ;

  // Connect to WiFi network
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);  

  // Wait until WiFi is connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nConnected to WiFi!");
  Serial.print("Local IP: ");
  // Print local IP address
  Serial.println(WiFi.localIP());  
}

void loop() {
  Serial.println("\nConnecting to server...");

  // Attempt to connect to the server
  if (client.connect(server_ip, server_port)) {
    Serial.println("Connected to server!");

    // Send a message to the server
    client.println("Hello From Arduino UNO R4");
    Serial.println("Sent: Hello From Arduino UNO R4");

    // Wait for a response from the server
    unsigned long timeout = millis() + 1000;
    while (client.available() || millis() < timeout) {
      if (client.available()) {
        String serverMessage = client.readStringUntil('\n');
        Serial.print("Server: ");
        Serial.println(serverMessage);
      }
    }

    client.stop();  // Close the connection
    Serial.println("Disconnected from server.");
  } else {
    // If connection fails, print message
    Serial.println("Connection failed.");  
  }

  delay(5000);  
}
