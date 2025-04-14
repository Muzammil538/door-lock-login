#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

String phone = "+919030196338"; // Your number with country code
String apikey = "YOUR_API_KEY"; // From CallMeBot

ESP8266WebServer server(80);
Servo myservo;

String loginPage = R"=====(
<!DOCTYPE html>
<html>
  <body>
    <h2>Login</h2>
    <form action="/login" method="POST">
      Username: <input type="text" name="user"><br><br>
      Password: <input type="password" name="pass"><br><br>
      <input type="submit" value="Login">
    </form>
  </body>
</html>
)=====";

void handleRoot() {
  server.send(200, "text/html", loginPage);
}

void handleLogin() {
  String user = server.arg("user");
  String pass = server.arg("pass");

  if (user == "admin" && pass == "1234") {
    myservo.write(90); // open door
    delay(3000);
    myservo.write(0);  // close door
    server.send(200, "text/html", "<h1>✅ Access Granted</h1>");
  } else {
    sendWhatsAppAlert();
    server.send(401, "text/html", "<h1>❌ Access Denied</h1>");
  }
}

void sendWhatsAppAlert() {
  WiFiClient client;
  const char* host = "api.callmebot.com";

  String msg = "⚠️ Failed Login Attempt on Door Lock System!";
  String url = "/whatsapp.php?phone=" + phone + "&text=" + msg + "&apikey=" + apikey;

  if (client.connect(host, 80)) {
    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                 "Host: " + host + "\r\n" +
                 "Connection: close\r\n\r\n");
  }
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  myservo.attach(D4);
  myservo.write(0); // Closed initially

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("\n📶 Wi-Fi connected");
  Serial.println("ESP IP : " + WiFi.localIP());

  server.on("/", handleRoot);
  server.on("/login", HTTP_POST, handleLogin);
  server.begin();
  Serial.println("🌐 Web server running!");
}

void loop() {
  server.handleClient();
}
