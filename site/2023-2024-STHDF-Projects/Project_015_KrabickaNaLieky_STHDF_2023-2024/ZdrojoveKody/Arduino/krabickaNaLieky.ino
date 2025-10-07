const int magnet_switch = 6;  // Magnet switch
const int buzzer = 12;        // Buzzer
const int led = 8;
const int buttonPin = 7;

int buttonState = LOW;
boolean wasOpened = false;

void setup() {
  pinMode(magnet_switch, INPUT_PULLUP);
  pinMode(buzzer, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  if (digitalRead(magnet_switch) == LOW && !wasOpened) {
    Serial.println("Switch Closed");
    noTone(buzzer);
    digitalWrite(led, HIGH);
  } else {
    wasOpened = true;
    digitalWrite(led, LOW);
    tone(buzzer, 1000);
    delay(3000);
    wasOpened = false;
  }
}
