#pragma once
#include <ESP8266WiFi.h>
#include <ArduinoJson.h>
extern WiFiClient client;
extern const char* host ;
extern const uint16_t port ;

class Iotkaran
{
public:
	void status();
	void disconnection();
	void connection();
	void send();
};
