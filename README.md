# MeteoHarvester

PlatformIO project within Visual Studio.

## Hardware pieces
- Esp8266 01
- DHT22

### ESP8266 01
You need make modify for DeepSleep mode. It is necessary for correct working and long term battery live. Yellow wire.
For circuit power source you need 3.3V. 2x1.5V is not enought. I use 18650 LiIon battery.
![DeepSleep modification](Accessories/Fritzing/DTH22_bb.png?raw=true)

## Setup
Before first run you must modify `src/Config.h` for:
- Wifi
- ThingSpeak settings
- Depp sleep mode time
- `ThingSpeakWithoutDHT22 = true` if you want try Esp8266 without DHT22
