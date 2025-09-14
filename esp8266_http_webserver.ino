#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

const char *ssid = "Головенець";
const char *password = "Головенець";


void handleRoot() 
{
  server.send(200, "text/html", "<h1>ІТІР-20-1 Головенець Максим<h1>");
}
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  WiFi.begin("TP-LINK_5425DC", "link-3323");

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.println("Waiting to connect...");
  }

 Serial.print("IP address: ");
 Serial.println(WiFi.localIP());

 server.on("/other", []()
 {
  server.send(200, "text / plain", "Other URL");
 });

 server.on("/grup", []()
 {
  server.send(200, "text / plain", "ITIР-20-1");
 }); 

 server.on("/name", []()
 {
  server.send(200, "text / plain", "Максим");
 });

 server.on("/surname", []()
 {
  server.send(200, "text / plain", "Головенець");
 });

 server.on("/data", []()
 {
  server.send(200, "text / plain", __DATE__);
 });

  server.on("/grup/name", []()
 {
  server.send(200, "text / plain", "ІТІР-20-1 Максим");
 });

  server.on("/grup/surname", []()
 {
  server.send(200, "text / plain", "ІТІР-20-1 Головенець");
 });

  server.on("/grup/name/surname", []()
 {
  server.send(200, "text / plain", "ІТІР-20-1 Максим Головенець");
 });

   server.on("/grup/name/surname", []()
 {
  server.send(200, "text / plain", "ІТІР-20-1 Максим Головенець" & __DATE__);
 });
 
 server.on("/", handleRootPath);
 server.begin();
 Serial.println("Server listening");
}


void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
}

void handleRootPath()
{
  server.send(200, "text/pain", "Hello simple HTTP webserver");
}
