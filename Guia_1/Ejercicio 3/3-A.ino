#define buzzer 6

void setup(){
    pinMode(3, OUTPUT);
    pinMode(5, OUTPUT);
  	pinMode(buzzer, OUTPUT);
}

void loop(){
  	digitalWrite(3, HIGH);
  	digitalWrite(5, LOW);
  	tone(buzzer, 2400);
    delay(800);
  	digitalWrite(3, LOW);
  	digitalWrite(5, HIGH);
    tone(buzzer, 1800);
    delay(800);
}