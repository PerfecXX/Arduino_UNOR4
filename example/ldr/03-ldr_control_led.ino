#define LDR_PIN A1
#define LED_PIN 8 

int ldr_val;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  ldr_val = analogRead(LDR_PIN);

  Serial.print("LDRValue:");
  Serial.println(ldr_val);

  if (ldr_val < 900){
    Serial.println("Too dark! - Turn on the LED");
    digitalWrite(LED_PIN, HIGH);
  }
  else{
    Serial.println("Normal light - Turn off the LED");
    digitalWrite(LED_PIN, LOW);
  }

  delay(100);

}
