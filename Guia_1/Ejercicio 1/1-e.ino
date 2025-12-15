//LED 1
#define rojo1 11
#define azul1 10
#define verde1 9
//LED 2
#define rojo2 6
#define azul2 5
#define verde2 3
void setup(){
  	pinMode(rojo1, OUTPUT);
  	pinMode(azul2, OUTPUT);
	pinMode(verde2, OUTPUT);
  	
  	pinMode(rojo2, OUTPUT);
  	pinMode(azul2, OUTPUT);
  	pinMode(verde2, OUTPUT);
}
void loop(){
  	
	digitalWrite(rojo1, 255);
    delay(500);
  	digitalWrite(rojo1, 0);
  	digitalWrite(rojo2, 255);
  	delay(500);
  	digitalWrite(rojo2, 0);
  
  	
  	digitalWrite(azul1, 255);
  	digitalWrite(verde1, 255);
  	delay(500);
  	digitalWrite(azul1, 0);
  	digitalWrite(verde1, 0);
    digitalWrite(azul2, 255);
  	digitalWrite(verde2, 255);
  	delay(500);
  	digitalWrite(azul2, 0);
  	digitalWrite(verde2, 0);
  
  	
  	digitalWrite(verde1, 255);
  	delay(500);
  	digitalWrite(verde1, 0);
  	digitalWrite(verde2, 255);
  	delay(500);
	digitalWrite(verde2, 0);
  
  
  	digitalWrite(rojo1, 255);
  	digitalWrite(azul1, 255);
  	delay(500);
  	digitalWrite(rojo1, 0);
  	digitalWrite(azul1, 0);
    digitalWrite(rojo2, 255);
  	digitalWrite(azul2, 255);
  	delay(500);
  	digitalWrite(rojo2, 0);
  	digitalWrite(azul2, 0);
  
  	
  	digitalWrite(azul1, 255);
  	delay(500);
  	digitalWrite(azul1, 0);
  	digitalWrite(azul2, 255);
  	delay(500);
  	digitalWrite(azul2, 0);
  
  
  	digitalWrite(rojo1, 255);
  	digitalWrite(verde1, 255);
  	digitalWrite(azul1, 255);
  	delay(500);
  	digitalWrite(rojo1, 0);
  	digitalWrite(verde1, 0);
  	digitalWrite(azul1, 0);
  	digitalWrite(rojo2, 255);
  	digitalWrite(verde2, 255);
  	digitalWrite(azul2, 255);
  	delay(500);
  	digitalWrite(rojo2, 0);
  	digitalWrite(verde2, 0);
  	digitalWrite(azul2, 0);
  
  
  	digitalWrite(rojo1, 255);
  	digitalWrite(verde1, 255);
  	delay(500);
  	digitalWrite(rojo1, 0);
  	digitalWrite(verde1, 0);
  	digitalWrite(rojo2, 255);
  	digitalWrite(verde2, 255);
  	delay(500);
  	digitalWrite(rojo2, 0);
  	digitalWrite(verde2, 0);
}