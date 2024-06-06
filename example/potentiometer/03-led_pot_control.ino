#define POT_PIN A0
#define LED_PIN 8

int pot_val;
int pot_percentage;
int led_val;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  
  pot_val = analogRead(POT_PIN);

  pot_percentage = map(pot_val, 0, 1023, 0, 100);
  led_val = map(pot_val, 0, 1023, 0, 255);
  
  analogWrite(LED_PIN, led_val);

  Serial.print("Potentiometer: ");
  Serial.println(pot_val);

  Serial.print("PotPercentage: ");
  Serial.println(pot_percentage);

  Serial.print("LEDBrightness: ");
  Serial.println(led_val);
  
  delay(100);
}
