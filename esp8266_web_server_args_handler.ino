#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

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

 server.on("/genericArgs", handleGenericArgs);
 server.on("/specificArgs", handleSpecificArgs);
 
 server.begin();
 Serial.println("Server listening");
}


void loop() {
  // put your main code here, to run repeatedly:
server.handleClient();
}


void handleGenericArgs()
{
  String massage = "Number of args received:";
  massage += server.args();
  massage += "\n";

  for(int i = 0; i<server.args(); i++)
  {
    massage += "Arg n" + (String)i + " --> ";
    massage += server.argName(i) + ": ";
    massage += server.arg(i) + "\n";
  }

  server.send(200, "text/plain", massage);
}

void handleSpecificArg()
{
  String massage = "";

  if (server.arg() != "ІТІР-20-1 Максим Головенець")
  {
    massage = "Параметри невірно вказані";
  }
  else {
    massage = " Argument = ";
    massage += server.arg("ІТІР-20-1 Максим Головенець");
  }

  server.send(200, "text/plain", massage);
}

