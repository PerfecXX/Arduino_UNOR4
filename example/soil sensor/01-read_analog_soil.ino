#define SOIL_PIN A3

int soil_val;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  soil_val = analogRead(SOIL_PIN);
  
  Serial.print("SoilSensorValue:");
  Serial.println(soil_val);

  delay(100);
}
