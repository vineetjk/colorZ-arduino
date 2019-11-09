# colorZ-Arduino
Smart RGB LED bulb made using ESP8266 (NodeMCU) and Firebase Realtime Database 

## Getting Started

Clone the repository

For [Android App](https://github.com/vineetjk/colorZ)
```
git clone "https://github.com/vineetjk/colorZ.git"
```
### Requirements
* Download [ESP8266](https://github.com/esp8266/Arduino) Library
* For Arduino
    * [ArduinoJson](https://www.arduinolibraries.info/libraries/arduino-json) v5.3.0 or above
    * [ Firebase Library ](https://github.com/FirebaseExtended/firebase-arduino/releases) 

### Installation

Change the Fingerprint present in ``` Arduino/libraries/firebase-arduino-0.3/src/FirebaseHttpClient.h ```
to
```
kFirebaseFingerprint[] =
      "B6:F5:80:C8:B1:DA:61:C1:07:9D:80:42:D8:A9:1F:AF:9F:C8:96:7D"
```
