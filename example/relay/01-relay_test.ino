#define RELAY_PIN 13

void setup() {

  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(RELAY_PIN, LOW);
}

void loop() {

  digitalWrite(RELAY_PIN, HIGH);
  delay(1000);
  
  
  digitalWrite(RELAY_PIN, LOW);
  delay(1000);
}
