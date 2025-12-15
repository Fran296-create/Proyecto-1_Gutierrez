#define boton 2
#define rojo1 3
#define azul2 4
#define verde3 5
#define rojo4 6
#define azul4 7
#define rojo5 8
#define verde5 9
#define azul6 10
#define verde6 11
#define rojo7 12
#define verde7 13
#define tiempo A0
bool iniciado = false;
void setup() {
  	pinMode(boton, INPUT_PULLUP);
  	pinMode(rojo1, OUTPUT);
    pinMode(verde3, OUTPUT);
    pinMode(rojo4, OUTPUT);
    pinMode(azul4, OUTPUT);
    pinMode(rojo5, OUTPUT);
    pinMode(verde5, OUTPUT);
    pinMode(azul6, OUTPUT);
    pinMode(verde6, OUTPUT);
    pinMode(rojo7, OUTPUT);
    pinMode(verde7, OUTPUT);
  	pinMode(tiempo, INPUT);
}

void loop(){
  	int espera = map(analogRead(tiempo), 0, 1023, 500, 10000);
  
    if (!iniciado){
        if (digitalRead(boton) == LOW){
            delay(50);
            if (digitalRead(boton) == LOW){
              iniciado = true;
            }
        }
    }
  	else{
        digitalWrite(rojo1, HIGH);
        delay(espera);
        digitalWrite(rojo1, LOW);
        delay(espera);

        digitalWrite(azul2, HIGH);
        delay(espera);
        digitalWrite(azul2, LOW);
        delay(espera);

        digitalWrite(verde3, HIGH);
        delay(espera);
        digitalWrite(verde3, LOW);
        delay(espera);

        analogWrite(rojo4, HIGH);
        digitalWrite(azul4, HIGH);
        delay(espera);
        analogWrite(rojo4, LOW);
        digitalWrite(azul4, LOW);
        delay(espera);

        digitalWrite(rojo5, HIGH);
        analogWrite(verde5, 165);
        delay(espera);
        digitalWrite(rojo5, LOW);
        analogWrite(verde5, 0);
        delay(espera);

        digitalWrite(azul6, HIGH);
        digitalWrite(verde6, HIGH);
        delay(espera);
        digitalWrite(azul6, LOW);
        digitalWrite(verde6, LOW);
        delay(espera);

        digitalWrite(rojo7, HIGH);
        digitalWrite(verde7, HIGH);
        delay(espera);
        digitalWrite(rojo7, LOW);
        digitalWrite(verde7, LOW);
        delay(espera);
    }
}