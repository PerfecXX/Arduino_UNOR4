#include "RTC.h"
#include <NTPClient.h>
#include <WiFiS3.h>
#include <WiFiUdp.h>

#define SSID "replace_with_your_ssid"
#define PASS "replace_with_your_password"

WiFiUDP Udp;
NTPClient timeClient(Udp);
RTCTime setting_time;
RTCTime currentTime;

int timeZoneOffsetHours = 7;  // Bangkok Time
long unixTime;

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

  RTC.begin();
  Serial.println("Starting connection to server...");
  timeClient.begin();
  timeClient.update();

  unixTime = timeClient.getEpochTime() + (timeZoneOffsetHours * 3600);
  Serial.print("Unix time: ");
  Serial.println(unixTime);

  setting_time = RTCTime(unixTime);
  RTC.setTime(setting_time);

  RTC.getTime(currentTime);
  Serial.println("RTC set to " + String(currentTime));
}

void loop() {}
