#include <ESP8266WiFi.h>
#include <Servo.h>

Servo myServo;
const char* ssid = "Your_SSID";
const char* password = "Your_WIFI_PASSWORD";
WiFiServer server(80);

void setup() {
  myServo.attach(D1);
  myServo.write(0);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) delay(500);
  Serial.println(WiFi.localIP());
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (!client) return;
  String request = client.readStringUntil('\r');
  client.flush();

  if (request.indexOf("/unlock") != -1) {
    myServo.write(90);
    delay(5000);
    myServo.write(0);
  }
  client.print("HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\nOK");
}