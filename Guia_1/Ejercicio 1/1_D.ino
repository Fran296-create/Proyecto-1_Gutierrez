void setup(){
  	pinMode(7, OUTPUT);
  	pinMode(8, OUTPUT);
	pinMode(9, OUTPUT);
}
void loop(){
  	digitalWrite(7, HIGH);
  	digitalWrite(9, HIGH);
  	delay(500);
  	digitalWrite(7, LOW);
  	digitalWrite(8, HIGH);
  	delay(500);
  	digitalWrite(7, HIGH);
	digitalWrite(8, LOW);
  	delay(500);
  	digitalWrite(7, LOW);
  	digitalWrite(8, HIGH);
  	delay(500);
  	digitalWrite(7, HIGH);
	digitalWrite(8, LOW);
  	delay(500);
   	digitalWrite(7, LOW);
  	digitalWrite(8, HIGH);
  	delay(500);
  	digitalWrite(8, LOW);
  	digitalWrite(9, LOW);
  	delay(5000);
}