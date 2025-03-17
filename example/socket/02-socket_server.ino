/*
Author      : Teeraphat Kullanankanjana
Version     : 1.0
Date        : 18/03/2025
Description : This code allows an Arduino to act as a TCP server. The server listens for incoming 
              client connections on a specified IP address and port. It receives data from clients, 
              processes the data, and sends a response back to the client.
Copyright (C) 2025 Teeraphat Kullanankanjana. All rights reserved.
*/

#include <WiFiS3.h>  // Include WiFi library for Arduino UNO R4 WiFi

// Replace with your WiFi credentials
const char* ssid = "REPLACE_WITH_YOUR_SSID";
const char* password = "REPLACE_WITH_YOUR_PASSWORD";

// Server settings
const int server_port = 1102; 

// Create a WiFi server object
WiFiServer server(server_port);  

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

  // Start the server
  server.begin();
  Serial.println("Server started!");
}

void loop() {
  // Check if a client has connected
  WiFiClient client = server.available();  

  if (client) {
    Serial.println("Client connected!");

    // Send a welcome message to the client
    client.println("Hello from the server!");

    // Wait for the client to send data
    unsigned long timeout = millis() + 1000;
    while (client.available() || millis() < timeout) {
      if (client.available()) {
        // Read message from client
        String clientMessage = client.readStringUntil('\n');  
        Serial.print("Client: ");
        // Print client message to serial monitor
        Serial.println(clientMessage);  

        // Send a response back to the client
        client.println("Message received by server!");
      }
    }
    // Close the client connection
    client.stop();  
    Serial.println("Client disconnected.");
  }
  // Add delay to avoid unnecessary CPU usage
  delay(100);  
}
