#define BTN_PIN 7

int btn_state;

void setup() {
  pinMode(BTN_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  btn_state = digitalRead(BTN_PIN);
  Serial.print("ButtonState:");
  Serial.println(btn_state);
  delay(500);
}
