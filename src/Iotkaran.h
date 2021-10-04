#pragma once
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
extern WiFiClient client;


class Iotkaran
{
  public:
    bool status();
    void send(String Input);
    void authentication(String Token);
    void connect(const char* host, const uint16_t port);
    void reconnect(const char* host, const uint16_t port);

};
