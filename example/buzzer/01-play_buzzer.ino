#define BUZZER_PIN 9

void setup() {
  pinMode(BUZZER_PIN,OUTPUT);
}

void loop() {
  tone(BUZZER_PIN,500);
  delay(1000);
  noTone(BUZZER_PIN);
  delay(1000);

}
