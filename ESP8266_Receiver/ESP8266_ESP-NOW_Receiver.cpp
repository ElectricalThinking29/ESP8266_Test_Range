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

// ********************* ESP-NOW Receiver ********************
// ****** This is the BEGIN of ESP-NOW Receiver program ******

#include <Arduino.h>
#include <espnow.h>
#include <ESP8266WiFi.h>

const int ledPin = LED_BUILTIN;

void OnDataReceived(uint8_t *macAddr, uint8_t *data, uint8_t dataLen) {
  Serial.print("Packet from: ");
  for (int i = 0; i < 6; i++) {
    Serial.print(macAddr[i], HEX);
    if (i < 5) {
      Serial.print(":");
    }
  }
  Serial.print(" data: ");
  Serial.println((char*)data);
  // Blink LED
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
}

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  WiFi.mode(WIFI_STA);
  // Init ESP-NOW
  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }
  esp_now_set_self_role(ESP_NOW_ROLE_SLAVE);
  esp_now_register_recv_cb(OnDataReceived);
  digitalWrite(ledPin, LOW);
}

void loop() {
}

// ******* This is the END of ESP-NOW Receiver program *******
// ***********************************************************