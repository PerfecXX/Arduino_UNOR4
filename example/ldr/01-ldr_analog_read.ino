#define LDR_PIN A1

int ldr_val;

void setup() {
  Serial.begin(9600);

}

void loop() {

  ldr_val = analogRead(LDR_PIN);

  Serial.print("LDRValue:");
  Serial.println(ldr_val);
  
  delay(100);

}
