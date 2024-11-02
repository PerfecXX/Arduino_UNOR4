#include "RTC.h"

RTCTime currenttime;

void setup() {
  Serial.begin(9600);

  RTC.begin();
  //            DAY MONTH            YEAR HOUR MINUTE SECOND    DAY OF WEEK            SAVE_LIGHT
  RTCTime mytime(2, Month::NOVEMBER, 2024, 13, 51, 00, DayOfWeek::SATURDAY, SaveLight::SAVING_TIME_ACTIVE);
  RTC.setTime(mytime);
}

void loop() {
 // Get current time from RTC
  RTC.getTime(currenttime);
  
  // Print out date (DD/MM//YYYY)
  Serial.print(currenttime.getDayOfMonth());
  Serial.print("/");
  Serial.print(Month2int(currenttime.getMonth()));
  Serial.print("/");
  Serial.print(currenttime.getYear());
  Serial.print(" - ");

  // Print time (HH/MM/SS)
  Serial.print(currenttime.getHour());
  Serial.print(":");
  Serial.print(currenttime.getMinutes());
  Serial.print(":");
  Serial.println(currenttime.getSeconds());

  delay(1000);
}
