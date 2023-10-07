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

/*** Copy right ***
  Rui Santos
  Complete project details at https://RandomNerdTutorials.com/esp-now-esp8266-nodemcu-arduino-ide/
  
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files.
  
  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.
*/

// ******************** ESP-NOW Sender *******************
// ***** This is the BEGIN of ESP-NOW Sender program *****

#include <Arduino.h>
#include <espnow.h>
#include <ESP8266WiFi.h>
// "FF:FF:FF:FF:FF:FF" is the default address, it just work fine. 
// But you should use exact Slave's MAC Address for security and not-missending
uint8_t broadcastAddress[] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF}; 
uint8_t message[] = "Hello from ESP8266";
const int messageSize = sizeof(message);

void OnDataSent(uint8_t *macAddr, uint8_t status) {
  Serial.print("Packet to: ");
  for (int i = 0; i < 6; i++) {
    Serial.print(macAddr[i], HEX);
    if (i < 5) {
      Serial.print(":");
    }
  }
  Serial.print(" send status: ");
  Serial.println(status == 0 ? "success" : "fail");
}

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  WiFi.mode(WIFI_STA);
  // Set Output Power
  WiFi.setOutputPower(20.5); // dBm
  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent);
  // Register peer
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
  Serial.println("ESP-NOW initalized successfully");
}

void loop() {
  esp_now_send(broadcastAddress, message, messageSize);
  Serial.println("Packet sent");
  digitalWrite(2, LOW);
  delay(500);
  digitalWrite(2, HIGH);
  delay(500);
}

// ***** This is the END of ESP-NOW Sender program *******
// *******************************************************