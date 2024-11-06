#include <WiFiS3.h>

#define SSID "replace_with_your_ssid"
#define PASS "replace_with_your_password"

void setup() {
  Serial.begin(9600);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SSID);
    WiFi.begin(SSID, PASS);
    delay(10000);
  }
  Serial.println("Connected to WiFi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
}
