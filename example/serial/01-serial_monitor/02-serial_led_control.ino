String receivedData = "";
char incomingChar;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial Receiver Ready");
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  while (Serial.available() > 0) 
  {
    incomingChar = Serial.read();
    if (incomingChar == '\n') 
    {
      Serial.print("Received: ");
      Serial.println(receivedData);
      
      if (receivedData == "on") {
        digitalWrite(LED_BUILTIN, HIGH);  
        Serial.println("LED is ON");
      } else if (receivedData == "off") {
        digitalWrite(LED_BUILTIN, LOW); 
        Serial.println("LED is OFF");
      }
      
      receivedData = "";
    } else 
    {
      receivedData += incomingChar;
    }
  }
}
