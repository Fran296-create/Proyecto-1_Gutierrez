#define pulsador 4
#define buzzer 8

void setup() {
  	pinMode(pulsador, INPUT_PULLUP);
  	pinMode(buzzer, OUTPUT);
}

void loop() {
  	if (digitalRead(pulsador) == LOW){
    	tone(buzzer, 1000);
    	delay(200);
    	noTone(buzzer);
    	delay(200);
    	tone(buzzer, 1500);
    	delay(200);
    	noTone(buzzer);
    	delay(200);
  	}
  	else{
    	noTone(buzzer);
  	}
}
