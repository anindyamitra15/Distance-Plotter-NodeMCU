#include <ESP8266WiFiMulti.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESP8266mDNS.h> 
#include "webpage.h"
#include <Ultrasonic.h>


#define trig 4
#define echo 5

// Sets the ultrasonic sensor
Ultrasonic ultrasonic(trig, echo);

ESP8266WiFiMulti manyPhones;
MDNSResponder MDNS;
AsyncWebServer server(80);//serves at port 80 (default)

const char* ssid1 = "WiFiAP";
const char* pass1 = "12345678";



//setup setup setup setup setup setup setup setup setup setup setup setup setup setup setup setup setup
void setup() {
    
    Serial.begin(115200);
    
    manyPhones.addAP(ssid1, pass1);
    
    WiFi.mode(WIFI_STA);
    
    while(WiFi.status() != WL_CONNECTED){
      delay(1000);
      Serial.println("Keep patience...");
    }
    
    Serial.print("Connected: ");
    Serial.println(WiFi.localIP());
    
    if (MDNS.begin("mcu-node", WiFi.localIP()))             // Start the mDNS responder for mcu-node.local
    Serial.println("mDNS responder started");
    
    // Route for web page
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send(200, "text/html", indexPage);
    });
    
    server.on("/distance", HTTP_GET, [](AsyncWebServerRequest *request){
      request->send_P(200, "text/plain", readDistance().c_str());  // converts the cpp string to c style string
    });
    
    // Start server
    server.begin();
    
    MDNS.addService("http", "tcp", 80);
}


void loop(){ MDNS.update(); }


String readDistance() {
  // Read Distance
  float t = ultrasonic.read();  // reads distance from the sensor

  t = ( t > 2 ) ? t : 2 ; // bounds the value above 2cm

  if (isnan(t)) { //if t is not a number (NaN)    
    Serial.println("Failed to read from HC-SR04 sensor!");
    return "";
  }
  else {
    Serial.println(t);
    return String(t);
  }
}
