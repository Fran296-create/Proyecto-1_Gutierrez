#include <Wire.h>


#define Rojo	9
#define Azul	10
#define Verde	11
#define Buzz	8
#define Mov 	3	
#define dis		2
#define boton	4

#define distanciaSegura   150
#define distanciaMedia    100
#define DistanciaPeligro  50

void setup()
{
  pinMode(Rojo , OUTPUT);
  pinMode(Azul , OUTPUT);
  pinMode(Verde, OUTPUT);
  
  pinMode(Mov  , INPUT );
  pinMode(dis  , INPUT );
  
  pinMode(Buzz , OUTPUT);
  
  pinMode(Boton, INPUT_PULLUP );
  
  Serial.begin(9600);
}

void loop()
{
  int valorDistancia = digitalRead(dis);
  Serial.print("Distancia actual del objeto: ");
  Serial.print(valorDistancia);
  Serial.Println(" cm");
  
  bool estadoActual = digitalWrite(boton);
  
  if (estadoActual == LOW && estadoAnterior == HIGH){
  	alarmaActiva = !alarmaActiva;
    delay(200);
  }
  
   estadoAnterior = EstadoAcutal;
  
  if (valorDistancia > distanciaSegura){
  	digitalWrite(Verde , HIGH);
    digitalWrite (Buzz , LOW); 
  }
  	
  if (valorDistancia > distanciaMedia){
  	digitalWrite(azul,HIGH);
    digitalWrite (Buzz, LOW);
  }
  
  if (valorDiastancia )
  
  
  
  
  
  
  int valorMovimiento = digitalRead(Mov);
}