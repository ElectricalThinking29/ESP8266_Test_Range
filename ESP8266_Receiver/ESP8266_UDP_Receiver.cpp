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

// *********************** UDP Receiver **********************
// ******** This is the BEGIN of UDP Receiver program ********

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

// Name and password of AP
const char* ssid = "ESP8266_AP";
const char* password = "12345678";
// IP Address and port of UDP server
const char* host = "192.168.4.1";
const int port = 80;
// Create UDP object to use the library
WiFiUDP udp;


void setup() {
  // Start debug serial port
  Serial.begin(115200);
  // Setting WiFi mode to Station
  WiFi.mode(WIFI_STA);
  // Connect to Wifi AP
  WiFi.begin(ssid, password);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  // Wait until connected
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  // Start binding with UDP port
  udp.stop();
  udp.begin(port);
  Serial.println("UDP started");
  // Send a message to UDP server
  udp.beginPacket(host, port);
  udp.println("Hello from ESP8266_STA");
  udp.endPacket();
  Serial.print("Connecting to UDP server ");
  Serial.println(host);
  // Setting GPIO 2(LED pin)'s mode to be output 
  pinMode(2, OUTPUT);
}

void loop() {
  // If there is any data from UDP port
  if (udp.parsePacket()) {
    // Read the data
    String line = udp.readStringUntil('\n');
    Serial.print("Received: ");
    Serial.println(line);
    // Blink LED
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(2, LOW);
  }
}

// ********* This is the END of UDP Receiver program *********
// ***********************************************************