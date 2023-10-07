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

// ********************** TCP Sender *********************
// ******* This is the BEGIN of TCP Sender program *******
#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

// Name and password of AP
const char* ssid = "ESP8266_AP";
const char* password = "12345678";
// IP Address and port of TCP server
IPAddress ip(192, 168, 4, 1);
IPAddress gateway(192, 168, 4, 1);
IPAddress subnet(255, 255, 255, 0);
const int port = 80;
// Create server object
ESP8266WebServer server(port);
// Create client object
WiFiClient client;

// Send message function
void sendMessage() {
  // Check is there any client connected
  if (client.connected()) {
    client.println("Hello from ESP8266_AP");
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

// HTTP request (if any) process function
void handleRoot() {
  // Send feedback HTTP message
  server.send(200, "text/plain", "Welcome to ESP8266_AP");
}

// Setup function
void setup() {
  // Start debug Serial port
  Serial.begin(115200);
  // Set Output Power
  WiFi.setOutputPower(20.5); // dBm
  // Set mode LED pin
  pinMode(2, OUTPUT);
  // Set Wifi mode to Access Point
  WiFi.mode(WIFI_AP);
  // Config static IP Address for AP
  WiFi.softAPConfig(ip, gateway, subnet);
  // Activate AP
  WiFi.softAP(ssid, password);
  Serial.print("AP IP address: ");
  Serial.println(WiFi.softAPIP());
  // Connect process function when there is any HTTP request to "/"
  server.on("/", handleRoot);
  // Start Web server
  server.begin();
  Serial.println("HTTP server started");
  // Setting timer iinterrpt, call sendMessage function every second
  timer1_attachInterrupt(sendMessage);
  timer1_enable(TIM_DIV16, TIM_EDGE, TIM_LOOP); // TIM_DIV16 -> 80MHz/16 = 5 ticks/us -> 1 tick = 0,2us
  timer1_write(5000000); // will call the function declared in timer1_attachInterrupt() after 5 000 000 ticks * 0,2us = 1s
}

// Loop function
void loop() {
  // Process any HTTP request to server, will macth the request with the function declared in server.on() method
  server.handleClient();
  // if there is no TCP client connect
  if (!client.connected()) {
    // Accept connection from TCP client
    client = server.client();
    // If there is TCP Client connected already
    if (client.connected()) {
      // Print to debug serial port
      Serial.println("TCP client connected");
    }
  }
}

// ******* This is the END of TCP Sender program *********
// *******************************************************