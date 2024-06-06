#define POT_PIN A0

int pot_val;

void setup() {
  Serial.begin(9600);
}

void loop() {
  pot_val = analogRead(POT_PIN);
  Serial.print("Potentiometer:");
  Serial.println(pot_val);
  delay(100);
}
