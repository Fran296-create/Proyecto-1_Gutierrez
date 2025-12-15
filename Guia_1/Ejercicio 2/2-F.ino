#define tiempo A0

void setup(){
	pinMode(3, OUTPUT);
}

void loop(){
  	int potValue = analogRead(tiempo);
    int espera = map(potValue, 0, 1023, 250, 10000);
  	
    analogWrite(3, 255);
  	delay(espera);
  
  	analogWrite(3, 0);
  	delay(espera);
}