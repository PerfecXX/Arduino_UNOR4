#define trigPin 11  
#define echoPin 10  

float duration;  
float distance; 

void setup() {
  pinMode(trigPin, OUTPUT);  
  pinMode(echoPin, INPUT);   
  Serial.begin(9600); 
}

void loop() {
  // Send a short pulse to trigger the sensor
  digitalWrite(trigPin, LOW);  // Ensure the trigger pin is low
  delayMicroseconds(2);        // Wait for 2 microseconds
  digitalWrite(trigPin, HIGH); // Set the trigger pin high
  delayMicroseconds(10);       // Wait for 10 microseconds
  digitalWrite(trigPin, LOW);  // Set the trigger pin low

  // Measure the duration of the pulse on the echo pin
  duration = pulseIn(echoPin, HIGH);  // Read the duration of the pulse in microseconds

  // Calculate the distance in centimeters
  // The speed of sound is 343 m/s or 0.0343 cm/μs
  // The duration is divided by 2 to account for the round trip
  distance = (duration * 0.0343) / 2;

  Serial.print("Distance:");
  Serial.println(distance);

  delay(100); 
}
