#define LDR_PIN A1

int ldr_val;
int light_percentage;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ldr_val = analogRead(LDR_PIN);
  light_percentage = map(ldr_val, 0, 1023, 0, 100);

  Serial.print("LDRValue:");
  Serial.println(ldr_val);

  Serial.print("LightPercentage:");
  Serial.println(light_percentage);

  delay(100);
}
