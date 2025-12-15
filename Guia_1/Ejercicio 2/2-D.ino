#define rojo 9
#define azul 10
#define verde 11
#define rojo2 3
#define azul2 5
#define verde2 6
#define tiempo A0

void setup() {
    pinMode(rojo, OUTPUT);
    pinMode(verde, OUTPUT);
    pinMode(azul, OUTPUT);
  	pinMode(rojo2, OUTPUT);
    pinMode(verde2, OUTPUT);
    pinMode(azul2, OUTPUT);
}

void loop() {
  	int potValue = analogRead(tiempo);
    int espera = map(potValue, 0, 1023, 500, 2000);
  	
    analogWrite(rojo, 255);
  	analogWrite(azul, 255);
  	analogWrite(rojo2, 255);
	analogWrite(verde2, 255);
  	delay(espera);
  
  	analogWrite(rojo, 0);
  	analogWrite(azul, 0);
  	analogWrite(rojo2, 0);
  	analogWrite(verde2, 0);
  	delay(espera);
}