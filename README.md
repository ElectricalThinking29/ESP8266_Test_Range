# ESP8266_Test_Range
Made by @ElectricalThinking29

# Description
+ This project is made to program two ESP8266 boards to communicate using 3 different protocol: TCP, UDP and ESP-NOW.
+ The purpose is to define which protocol will help ESP8266 communicate furthest and how far is that distance.
+ This project is made from PlatformIO on VS Code

# How to use
+ First, you need two board ESP8266 and configure your IDE (Arduino IDE or PlatformIO) to be able to program. You can consult the configuration for ESP8266 12-E if you are using PlatformIO [here](platformio.ini)
+ Second, you need to decide which board will be [the sender](ESP8266_Sender) and which is [the receiver](ESP8266_Receiver). In each folders, you will find 3 programs corresponding to 3 protocols, use it wisely.

# Results and Reviews
+ Below is the result's data.
![Result2](result.jpg)
+ As you can see, the error is pretty large, from few to over 100 %. If we ignore the case
where the transmission's velocity is negative, the error is still go up to 50 %.
+ There are a number of issues that I think will improve measurement results:
  * Using more appropriate hardwares for measuring Time of Flight (ToF) of the message via WIfi
  * Using CSI data to get better timming
  * Improving the programs for better and faster reading
+ Even though I did this project just for fun and to satisfy my curiosity, I also don't mind listening
to your comments. If you want to ask questions, you can contact me at the address below.

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
