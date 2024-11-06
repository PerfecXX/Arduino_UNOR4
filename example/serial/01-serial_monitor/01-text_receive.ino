String receivedData = "";
char incomingChar;

void setup() {
  Serial.begin(9600);
  Serial.println("Serial Receiver Ready");
}

void loop() {
  while (Serial.available() > 0) 
  {
    incomingChar = Serial.read();
    if (incomingChar == '\n') 
    {
      Serial.print("Received: ");
      Serial.println(receivedData);
      receivedData = "";
    } else 
    {
      receivedData += incomingChar;
    }
  }
}
