#define IR_PIN 2

int ir_state;

void setup() {
  pinMode(IR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  ir_state = digitalRead(IR_PIN);
  
  Serial.print("IRState:");
  Serial.println(ir_state);

  delay(500);
}
