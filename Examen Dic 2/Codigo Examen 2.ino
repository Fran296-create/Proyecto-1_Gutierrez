#define RGB_A	9
#define RGB_R	8
#define RGB_V	10

#define buzz	7

#define temp_pin	A0
#define luz_pin 	A1

#define boton	6

bool ultimoEstadoBoton = HIGH;

void setup()
{
  Serial.begin(9600);
  pinMode( RGB_A , OUTPUT);
  pinMode( RGB_R , OUTPUT);
  pinMode( RGB_V , OUTPUT);
 
  
  pinMode( buzz , OUTPUT);
  
  pinMode( boton, INPUT_PULLUP);
}

void loop()
{
 bool estadoBoton = digitalRead(boton);
  
  
  if (estadoBoton == LOW && ultimoEstadoBoton == HIGH){
  	int lecturaT = analogRead(temp_pin);
    
    if (lecturaT <= 0 && lecuraT >= 100){
		digitalWrite( RGB_A , LOW);
        digitalWrite( RGB_R , HIGH);    
        digitalWrite( RGB_V , LOW);
        delay(200);
        digitalWrite( RGB_A , LOW);
        digitalWrite( RGB_R , LOW);    
        digitalWrite( RGB_V , LOW);
        delay(200);
      
      
        digitalWrite(buzz , HIGH );
        delay(400);
        digitalWrite( buzz, LOW);
        delay(400);
      
    }else if ( lecturaT >= 60 && lecturaT <= 80){
		digitalWrite( RGB_A , LOW);
        digitalWrite( RGB_R , LOW);    
        digitalWrite( RGB_V , HIGH);
      
      digitalWrite(buzz, LOW);
      
    }else{
        // amarillo
        digitalWrite( RGB_A , LOW);
        digitalWrite( RGB_R , HIGH);    
        digitalWrite( RGB_V , HIGH);
    
    digitalWrite(buzz, LOW);
    }
      
  }
  
  ultimoEstadoBoton == estadoBoton;
  
  if (estadoBoton == HIGH && ultimoEstadoBoton == LOW){
  
    int lecturaL  = analogRead(luz_pin);
    int luzPorcentaje = map(lecturaL, 0, 1023, 100, 0);
    
    if (luzPorcentaje >= 50){
        digitalWrite( RGB_A , HIGH);
        digitalWrite( RGB_R , LOW);    
        digitalWrite( RGB_V , LOW);
    }else{
        digitalWrite( RGB_A , LOW);
        digitalWrite( RGB_R , LOW);    
        digitalWrite( RGB_V , HIGH); 
  }
  
    if (estadoBoton == LOW && ultimoEstadoBoton == HIGH){
      int lecturaT = analogRead(temp_pin);
      int lecturaL  = analogRead(luz_pin);
    int luzPorcentaje = map(lecturaL, 0, 1023, 100, 0);
      Serial.print("TEMPERATURA: ");
      Serial.print(lecturaT);
      Serial.print(" °c   | ");
      Serial.print("LUZ :");
      Serial.print(luzPorcentaje);
      Serial.println(" lm");
      
      
    
    }
  
  
  
  
  
}