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

// *********************** TCP Receiver **********************
// ******** This is the BEGIN of TCP Receiver program ********

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>

// Name and password of AP
const char* ssid = "ESP8266_AP";
const char* password = "12345678";
// IP Address and port of server
const char* host = "192.168.4.1";
const int port = 80;
// Create WiFiClient object to use the library
WiFiClient client;

void setup() {
  // Start debug serial port
  Serial.begin(115200);
  // Setting Wifi mode to Station
  WiFi.mode(WIFI_STA);
  // Start connect to Wifi AP
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
  // Connect to TCP Server
  client.connect(host, port);
  Serial.print("Connecting to TCP server ");
  Serial.println(host);
  // Setting GPIO 2(LED pin)'s mode to be output 
  pinMode(2, OUTPUT);
}

void loop() {
  // Check if client is connected
  if (client.connected()) {
    // Check if any data available from TCP ServerN
    if (client.available()) {
      // read the data
      String line = client.readStringUntil('\n');
      Serial.print("Received: ");
      Serial.println(line);
      // Blink LED
      digitalWrite(2, HIGH);
      delay(500);
      digitalWrite(2, LOW);
    }
  }
  else
  {
    Serial.println("Can not connect to server");
    delay(1000);
  }
  
}

// ********* This is the END of TCP Receiver program *********
// ***********************************************************