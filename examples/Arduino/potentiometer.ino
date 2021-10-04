int sensorPin = A0;  
int sensorValue = 0;  

void setup() {
Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * (5.0 / 1023.0);

  Serial.print("sensorValue:");
  Serial.println(sensorValue);

  Serial.print("voltage:");
  Serial.println(voltage);

  delay(3000);
}
