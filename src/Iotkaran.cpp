#include "Iotkaran.h"
WiFiClient client;


void Iotkaran::connect(const char* host, const uint16_t port)
{
  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  while (!client.connect(host, port))
  {
    delay(500);
    Serial.print(".");
  }
}

void Iotkaran::reconnect(const char* host, const uint16_t port)
{
  Serial.print("connecting to ");
  Serial.print(host);
  Serial.print(':');
  Serial.println(port);

  while (!client.connect(host, port))
  {
    delay(500);
    Serial.print(".");
  }
}
void Iotkaran::send(String Input)
{

  String A = Input + '\r' + '\n';

  client.print(A);
}

void Iotkaran::authentication(String Token)
{
  DynamicJsonDocument doc(1536);
  doc["Token"] = Token;
  String Output;
  serializeJson(doc, Output);
  Serial.print("Send to server:   ");
  Serial.println(Output);
  String A = Output + '\r' + '\n';

  client.print(A);
}

bool Iotkaran::status()
{
  if (client.connected())
  {
    return true;
  }
  else if (!client.connected())
  {
    return false;
  }
}
