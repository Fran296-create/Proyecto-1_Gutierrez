#define ledr 9
#define ledg 11
#define ledb 10

#define led2r 2
#define led2g 7
#define led2b 4

#define led3r 3
#define led3g 6
#define led3b 5

void setup(){
   pinMode(2, OUTPUT);
 pinMode(4, OUTPUT);
 pinMode(7, OUTPUT);
   
   pinMode(5, OUTPUT);
 pinMode(3, OUTPUT);
 pinMode(6, OUTPUT);
 
   pinMode(11, OUTPUT);
 pinMode(9, OUTPUT);
 pinMode(10, OUTPUT);
 
   pinMode(12, OUTPUT);
}

void loop(){
   analogWrite(ledr, 255);
 delay(1000);
 analogWrite(ledr, 0);
   delay(50);
   
   delay(10);
   digitalWrite(12, HIGH);
   delay(80);
    digitalWrite(12, LOW);
  delay(10);
   
   digitalWrite(led2r, 255);
   digitalWrite(led2b, 255);
 delay(1000);
    digitalWrite(led2r, 0);
   digitalWrite(led2b, 0);
 
   delay(10);
    digitalWrite(12, HIGH);
   delay(80);
    digitalWrite(12, LOW);
  delay(10);
   
   digitalWrite(led3g, 255);
   digitalWrite(led3b, 255);
 delay(1000);
    digitalWrite(led3g, 0);
   digitalWrite(led3b, 0);
 
   delay(10);
    digitalWrite(12, HIGH);
   delay(80);
    digitalWrite(12, LOW);
  delay(10);
}