byte COUNT = 3;
byte INPUTS[] = {2, 3, 4};
byte LEDS[] = {9, 11, 10};
String NAMES[] = {"red", "green", "blue"};
byte RESET_PIN = 5;

byte state = 0;
bool flag = true;

void setup() {
  Serial.begin(115200);
  
  for(int i = 0; i < COUNT; i++) {
    pinMode(INPUTS[i], INPUT_PULLUP);  
    pinMode(LEDS[i], OUTPUT);
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

        Serial.print("Team: ");
        Serial.println(NAMES[state]);
      }
    }
  } else {
    analogWrite(LEDS[state], 255); 
  }
}
