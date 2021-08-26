#include "Iotkaran.h"
const char* host = "server.Iotkaran.ir";
const uint16_t port = 2323;
WiFiClient client;


void Iotkaran::status()
{
    if (client.connected())
    {
        Serial.println("The client connected");
    }
    else if (!client.connected())
    {
        Serial.println("The client disconnected");
    }
}

void Iotkaran::disconnection()
{
    client.stop();
}

void Iotkaran::connection()
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


void Iotkaran::send()
{
    DynamicJsonDocument doc(1536);
    doc["Token"] = "1111";
    String Output;
    serializeJson(doc, Output);
    Serial.print("Send to server:   ");
    Serial.println(Output);
    client.print(Output);
}
