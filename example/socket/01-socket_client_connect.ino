#include <WiFiS3.h>

const char* ssid = "REPLACE_WITH_YOUR_SSID";   
const char* password = "REPLACE_WITH_YOUR_PASSWORD"; 

const char* server_ip = "192.168.1.105"; 
const int server_port = 1102;          

WiFiClient client;

void setup() {
    Serial.begin(9600);
    while (!Serial);

    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
        Serial.print(".");
    }

    Serial.println("\nConnected to WiFi!");
    Serial.print("Local IP: ");
    Serial.println(WiFi.localIP());

    if (client.connect(server_ip, server_port)) {
        Serial.println("Connected to server!");
        client.println("Hello from Arduino UNO R4!");
    } else {
        Serial.println("Connection to server failed.");
    }
}

void loop() {
  
}
