#define LED_PIN 2
#define BTN_PIN 7

int btn_state;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  btn_state = digitalRead(BTN_PIN);
  Serial.print("ButtonState:");
  Serial.println(btn_state);

  if (btn_state == 1){
    Serial.println("Button Pressed! - LED ON!");
    digitalWrite(LED_PIN,HIGH);
  }
  else {
    Serial.println("Button Not Pressed! - LED OFF!");
    digitalWrite(LED_PIN,LOW);
  }
  delay(500);
}
