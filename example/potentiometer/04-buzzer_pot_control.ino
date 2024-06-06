#define POT_PIN A0
#define BUZZER_PIN 9

int pot_val;
int pot_percentage;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  pot_val = analogRead(POT_PIN);
  pot_percentage = map(pot_val, 0, 1023, 0, 100);

  Serial.print("Potentiometer:");
  Serial.println(pot_val);

  Serial.print("PotPercentage:");
  Serial.println(pot_percentage);

  analogWrite(BUZZER_PIN, pot_percentage);

  delay(100);
}
