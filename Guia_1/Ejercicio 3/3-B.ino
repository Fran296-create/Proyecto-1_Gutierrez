#define ledr 9
#define ledb 10
#define ledg 11

#define potRojo A1
#define potAzul A2
#define potVerde A3

#define boton 2

bool iniciado = false;

void setup(){
    pinMode(ledr, OUTPUT);
    pinMode(ledb, OUTPUT);
    pinMode(ledg, OUTPUT);

    pinMode(potRojo, INPUT);
    pinMode(potAzul, INPUT);
    pinMode(potVerde, INPUT);

    pinMode(boton, INPUT_PULLUP);
}

void loop(){
    if (!iniciado){
        if (digitalRead(boton) == LOW){
            delay(50);
            if (digitalRead(boton) == LOW){
                iniciado = true;
            }
        }
    }
  else{
        int valorRojo = analogRead(potRojo);
        int valorAzul = analogRead(potAzul);
        int valorVerde = analogRead(potVerde);

        int rojo = map(valorRojo, 0, 1023, 0, 255);
        int azul = map(valorAzul, 0, 1023, 0, 255);
        int verde = map(valorVerde, 0, 1023, 0, 255);

        analogWrite(ledr, rojo);
        analogWrite(ledb, azul);
        analogWrite(ledg, verde);
    }
    delay(100);
}