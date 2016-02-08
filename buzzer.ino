byte COUNT = 3;
byte INPUTS[] = {2, 3, 4};
byte LEDS[] = {9, 11, 10};
byte RESET_PIN = 5;

byte state = 0;
bool flag = true;

void setup() {
  for(int i = 0; i < COUNT; i++) {
    pinMode(INPUTS[i], INPUT_PULLUP);  
  }
  
  pinMode(RESET_PIN, INPUT_PULLUP);
}

void loop() {
  if(digitalRead(RESET_PIN) == LOW) {
    flag = true;
  }

  if(flag) {
    for(byte i = 0; i < COUNT; i++) {
      analogWrite(LEDS[i], 0);

      if(digitalRead(INPUTS[i]) == LOW) {
        flag = false;
        state = i;
      }
    }
  } else {
    analogWrite(LEDS[state], 255); 
  }
}
