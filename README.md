# MeteoHarvester

PlatformIO project within Visual Studio.

## Hardware pieces
- Esp8266 01
- DHT22

### ESP8266 01
You need make modify for DeepSleep mode. It is necessary for correct working and long term battery live. Yellow wire.

![DeepSleep modification](Accessories/Fritzing/DTH22_bb.png?raw=true)

## Setup
Before first run you must modify `src/Secret.h` for:
- Wifi
- ThingSpeak settings
- Depp sleep mode time
- `ThingSpeakWithoutDHT22 = true` if you want try Esp8266 without DHT22