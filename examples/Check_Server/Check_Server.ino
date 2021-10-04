#include <Iotkaran.h>

unsigned long Timeout, status_time;

const char* ssid = "mohamad";
const char* password = "13750921";
Iotkaran IK;



void setup() {
  Serial.begin(115200);

  // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);


  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  IK.connection();
  IK.send();
  IK.disconnection();

}

void loop() {

}
