#include "RTC.h"
#include <NTPClient.h>
#include <WiFiS3.h>
#include <WiFiUdp.h>

#define SSID "iMakeEDU"
#define PASS "imake1234"

WiFiUDP Udp;
NTPClient timeClient(Udp);
RTCTime setting_time;
RTCTime currentTime;

int timeZoneOffsetHours = 7;  // Bangkok Time
long unixTime;

int current_day;
int current_month;
int current_year;
int current_hour;
int current_minute;
int current_second;

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

  Serial.println("RTC Clock Start!");
}

void loop() {

  RTC.getTime(currentTime);

  current_day = currentTime.getDayOfMonth();
  current_month = Month2int(currentTime.getMonth());
  current_year = currentTime.getYear();
  current_hour = currentTime.getHour();
  current_minute = currentTime.getMinutes();
  current_second = currentTime.getSeconds();

  Serial.print(current_day);
  Serial.print("/");
  Serial.print(current_month);
  Serial.print("/");
  Serial.print(current_year);
  Serial.print(" - ");

  Serial.print(current_hour);
  Serial.print(":");
  Serial.print(current_minute);
  Serial.print(":");
  Serial.println(current_second);

  delay(1000);
}
