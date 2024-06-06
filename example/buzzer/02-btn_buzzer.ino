#define BUZZER_PIN 9
#define BTN_PIN 7

int btn_state;

void setup() {
  pinMode(BUZZER_PIN,OUTPUT);
  pinMode(BTN_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  
  btn_state = digitalRead(BTN_PIN);
  Serial.print("ButtonState:");
  Serial.println(btn_state);

  if (btn_state == 1){
    Serial.println("Button Pressed! - Buzzer ON!");
    tone(BUZZER_PIN,500);
  }
  else {
    Serial.println("Button Not Pressed! - Buzzer OFF!");
    noTone(BUZZER_PIN);
  }
  delay(100);
}
