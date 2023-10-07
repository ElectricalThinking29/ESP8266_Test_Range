// If you can, please support me on my Youtube's channel: @ElectricalThinking29
// by hitting like, share and subscribe's buttons to my videos.

/*** LICENSE ***

Copyright 2023 @ElectricalThinking29

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

*/

// ********************** UDP Sender *********************
// ******* This is the BEGIN of UDP Sender program *******

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// Name and password of AP
const char* ssid = "ESP8266_AP";
const char* password = "12345678";
// IP Address and port of UDP server
IPAddress ip(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
const int port = 80;
// Create UDP object
WiFiUDP udp;

// Send-message-to-UDP-Client Function
void sendMessage() {
  // If there is UDP Client connected
  if (udp.remoteIP() != IPAddress(0, 0, 0, 0)) {
    // Send message to UDP client
    udp.beginPacket(udp.remoteIP(), udp.remotePort());
    udp.println("Hello from ESP8266_AP");
    udp.endPacket();
    Serial.println("Sent: Hello from ESP8266_AP");
    switch (digitalRead(2))
    {
    case HIGH:
      digitalWrite(2, LOW);
      break;
    case LOW:
      digitalWrite(2, HIGH);
      break;
    default:
      break;
    }
  }
}

// Setup function
void setup() {
  // Start debug serial port
  Serial.begin(115200);
  // Set Output Power
  WiFi.setOutputPower(20.5); // dBm
  // Set pin LED pin
  pinMode(2, OUTPUT);
  // Setting Wifi mode to Access Point
  WiFi.mode(WIFI_AP);
  // Setting static IP Address for AP
  WiFi.softAPConfig(ip, gateway, subnet);
  // Start AP
  WiFi.softAP(ssid, password);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
  // Start UDP
  udp.begin(port);
  Serial.println("UDP started");
}

// loop function
void loop() {
  // Check if there is any data from UDP client
  if (udp.parsePacket()) {
    String line = udp.readStringUntil('\n');
    Serial.print("Received: ");
    Serial.println(line);
  }
  sendMessage();
  delay(1000);
}

// ******* This is the END of UDP Sender program *********
// *******************************************************
