#define USE_ARDUINO_INTERRUPTS true
#define DEBUG true

#include <PulseSensorPlayground.h>
#include <SoftwareSerial.h>
#include <SerialESP8266wifi.h>


// konstanty
#define SSID "fillHere";                  // nazov WiFi
#define PASS "fillHere";                  // WiFi heslo

#define SSID2 "fillHere";              
#define PASS2 "fillHere"; 

#define IP "184.106.153.149";               // thingspeak.com ip
String msg = "GET /update?key=fillHere";    // API kluc

SoftwareSerial swSerial(14, 13);
SerialESP8266wifi wifi(swSerial, swSerial, 10, Serial);

SoftwareSerial esp8266(14, 13); // RX, TX
PulseSensorPlayground pulseSensor;
const int PulseWire = 0;
const int LED13 = 13;
int Threshold = 550;

// premenne
volatile int BPM;

// nastavenie
void setup() {
  Serial.begin(9600);
  Serial.println("STARTING DOG-FIT");

  pulseSensor.analogInput(PulseWire);
  pulseSensor.blinkOnPulse(LED13);
  pulseSensor.setThreshold(Threshold);

  if (pulseSensor.begin()) {
    Serial.println("Pulse Sensor starting");
  }

  esp8266.begin(9600);
  
  Serial.println("Serial connected");
  esp8266.println("WiFi module connected");
  delay(5000);
  connectWiFi();
}

// driver kod
void loop() {
  int myBPM = pulseSensor.getBeatsPerMinute();

  if (pulseSensor.sawStartOfBeat()) {
    Serial.println("♥");
    Serial.print("BPM: ");
    Serial.println(myBPM);
    sendToThingspeak(myBPM);
  }

  delay(20);
}

// odosielanie dat
void sendToThingspeak(int bpm) {
  Serial.println("Sending data to ThingsSpeak");
  String cmd = "AT+CIPSTART=\"TCP\",\"";
  cmd += IP;
  cmd += "\",80";
  //Serial.println(cmd);
  //esp8266.println(cmd);
  delay(2000);

  if (esp8266.find("Error")) {
    return;
  }

  cmd = msg;
  cmd += "&field1=";
  cmd += bpm;
  cmd += "\r\n";
  //Serial.print("AT+CIPSEND=");
  //esp8266.print("AT+CIPSEND=");
  //Serial.println(cmd.length());
  //esp8266.println(cmd.length());

  if (esp8266.find(">")) {
    //Serial.print(cmd);
    //esp8266.print(cmd);
  } else {
    //Serial.println("AT+CIPCLOSE");
    //esp8266.println("AT+CIPCLOSE");
  }
}

// pripajanie na WiFi
boolean connectWiFi() {
  Serial.println("Connecting to WiFi");
  boolean esp8266started = wifi.begin();

  // propojenie na WiFi 1 
  boolean apConnected = false;
  wifi.connectToAP("fillHere", "fillHere");
  apConnected = wifi.isConnectedToAP();

  if (apConnected) {
    Serial.println("WiFi 1 connected");
    return true;
  } else {
    Serial.println("Error connecting to WiFi 1");
    // propojenie na WiFi 2 
    wifi.connectToAP("fillHere", "fillHere");
    apConnected = wifi.isConnectedToAP();
    
    if (apConnected) {
      Serial.println("WiFi 2 connected");
      return true;
    } else {
      Serial.println("Error connecting to WiFi 2");
      return false;
    }
  }
}

boolean connectWiFi2() {
  // propojenie na WiFi 1 (home WiFi)
  Serial.println("AT+CWMODE=1");
  esp8266.println("AT+CWMODE=1");
  delay(2000);
  String cmd = "AT+CWJAP=\"";
  cmd += SSID;
  cmd += "\",\"";
  cmd += PASS;
  cmd += "\"";
  Serial.println(cmd);
  esp8266.println(cmd);

  delay(5000);

  if (esp8266.find("OK")) {
    Serial.println("WiFi 1 connected");
    return true;
  } else {
    Serial.println("Error connecting to WiFi 1");
    // propojenie na WiFi 2 (mobile WiFi)
    Serial.println("Resetting ESP8266...");
    esp8266.println("AT+RST");
    delay(5000);
    Serial.println("AT+CWMODE=1");
    esp8266.println("AT+CWMODE=1");
    delay(2000);
    String cmd = "AT+CWJAP=\"";
    cmd += SSID2;
    cmd += "\",\"";
    cmd += PASS2;
    cmd += "\"";
    Serial.println(cmd);
    esp8266.println(cmd);
    delay(5000);

    if (esp8266.find("OK")) {
      Serial.println("WiFi 2 connected");
      return true;
    } else {
      Serial.println("Error connecting to WiFi 2");
      return false;
    }
  }
}
