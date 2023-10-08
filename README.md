# ESP8266_Test_Range
Made by @ElectricalThinking29

# Description
+ This project is made to program two ESP8266 boards to communicate using 3 different protocol: TCP, UDP and ESP-NOW.
+ The purpose is to define which protocol will help ESP8266 communicate furthest and how far is that distance.
+ This project is made from PlatformIO on VS Code

# How to use
+ First, you need two board ESP8266 and configure your IDE (Arduino IDE or PlatformIO) to be able to program. You can consult the configuration for ESP8266 12-E if you are using PlatformIO [here](platformio.ini)
+ Second, you need to decide which board will be [the sender](ESP8266_Sender) and which is [the receiver](ESP8266_Receiver). In each folders, you will find 3 programs corresponding to 3 protocols, use it wisely.

# Results
+ I conducted this experiment outdoors. The results can be summarized as follows:
```
|_Protocol_|_Communicated distance_|
|   TCP    |          24 m         |
|   UDP    |          17 m         |
|  ESP-NOW |          60 m         |
```
> **Note**
> + I used the ESP8266 without any additional signal support devices (like antennas).
> + Because I use visualization to judge whether the packet transmission is successful or failed (when I wait for the LED light for too long, I consider it failed), so the distance values mentioned above are not 100% accurate.
> + 

# Youtube Channel
+ You can watch this project's video on Youtube: https://youtu.be/mwmY_hU-UsM
+ If you can, please support me on my Youtube's channel: @ElectricalThinking29.

# Contact
+ E-mail: electricalthinking29@gmail.com

# License
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
