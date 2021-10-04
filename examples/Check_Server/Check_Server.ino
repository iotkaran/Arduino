#include <Iotkaran.h>
#define Token  "enter your token here"

unsigned long Timeout, status_time;

const char* ssid = "enter ssid wifi here";
const char* password = "enter wifi password here";
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

  IK.connect("server.Iotkaran.ir" , 2323);   //Enter a host address and port
  IK.authentication(Token);
}

void loop() {

}
