#include "RTClib.h"

RTC_DS1307 rtc;

void setup () {
  Serial.begin(9600);

#ifndef ESP8266
  while (!Serial); // wait for serial port to connect. Needed for native USB
#endif

  if (! rtc.begin()) {
    Serial.println("Couldn't find RTC");
    Serial.flush();
    abort();
  }

  if (! rtc.isrunning()) {
    Serial.println("RTC is NOT running, let's set the time!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  }
  rtc.adjust(DateTime(2021, 9, 04, 14, 37, 55));
}

void loop() {
  DateTime time = rtc.now();

  //Full Timestamp
  Serial.println(String("DateTime::TIMESTAMP_FULL:\t") + time.timestamp(DateTime::TIMESTAMP_FULL));

  //Date Only
  Serial.println(String("DateTime::TIMESTAMP_DATE:\t") + time.timestamp(DateTime::TIMESTAMP_DATE));

  //Full Timestamp
  Serial.println(String("DateTime::TIMESTAMP_TIME:\t") + time.timestamp(DateTime::TIMESTAMP_TIME));

  Serial.println("\n");

  //Delay 5s
  delay(5000);
}
