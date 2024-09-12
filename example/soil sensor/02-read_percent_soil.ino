#define SOIL_PIN A3

int soil_val;
int soil_percentage;

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  soil_val = analogRead(SOIL_PIN);
  soil_percentage = map(soil_val, 0, 1023, 0, 100);
  
  Serial.print("SoilSensorValue:");
  Serial.println(soil_val);

  Serial.print("SoilPercentage:");
  Serial.println(soil_percentage);

  delay(100);
}
