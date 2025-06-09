# Dog-Fit Readme

## Description
This Arduino code is designed for the Dog-Fit project, utilizing a Pulse Sensor to monitor the heart rate of a dog and sending the data to the ThingSpeak platform for further analysis. The code is written for the ESP8266 WiFi module and incorporates the PulseSensorPlayground library.

## Dependencies
- PulseSensorPlayground library
- SoftwareSerial library
- SerialESP8266wifi library

## Configuration
- Set the WiFi credentials (SSID and PASSWORD) for both primary and backup networks.
- Configure the ThingSpeak IP address and API key in the "msg" variable.

## Hardware Setup
1. Connect the Pulse Sensor to the analog input specified in "PulseWire."
2. Connect the LED indicator to pin 13 (or modify the code to your preferred pin).
3. Connect the ESP8266 WiFi module using the SoftwareSerial pins specified.

## Constants
- `USE_ARDUINO_INTERRUPTS`: Set to `true` to use Arduino interrupts.
- `DEBUG`: Set to `true` for debug mode, providing additional information in the Serial Monitor.

## Variables
- `BPM`: Stores the heart rate in beats per minute.

## Setup
- Initializes the Pulse Sensor, sets the threshold, and establishes a connection to WiFi networks.

## Functions
- `sendToThingspeak(int bpm)`: Placeholder for the function to send heart rate data to ThingSpeak.
- `connectWiFi()`: Attempts to connect to the primary and backup WiFi networks.

## Usage
1. Upload the code to your Arduino board.
2. Open the Serial Monitor to observe the Dog-Fit's startup process and debug information.
3. Monitor the heart rate readings and data transmission to ThingSpeak.

## Note
Ensure that the required libraries are installed before uploading the code to your Arduino board.