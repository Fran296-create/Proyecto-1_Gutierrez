#define rojo 9
#define verde 10
#define azul 11

void setup() {
    pinMode(rojo, OUTPUT);
    pinMode(verde, OUTPUT);
    pinMode(azul, OUTPUT);
}

void loop() {
    // Cian suave
    analogWrite(rojo, 0);
    analogWrite(verde, 85);
    analogWrite(azul, 85);
    delay(1000);

    // Cian normal
    analogWrite(rojo, 0);
    analogWrite(verde, 170);
    analogWrite(azul, 170);
    delay(1000);

    // Cian fuerte
    analogWrite(rojo, 0);
    analogWrite(verde, 255);
    analogWrite(azul, 255);
    delay(1000);

    // Rojo suave
    analogWrite(rojo, 85);
    analogWrite(verde, 0);
    analogWrite(azul, 0);
    delay(1000);

    // Rojo normal
    analogWrite(rojo, 170);
    analogWrite(verde, 0);
    analogWrite(azul, 0);
    delay(1000);

    // Rojo fuerte
    analogWrite(rojo, 255);
    analogWrite(verde, 0);
    analogWrite(azul, 0);
    delay(1000);

    // Amarillo suave
    analogWrite(rojo, 85);
    analogWrite(verde, 85);
    analogWrite(azul, 0);
    delay(1000);

    // Amarillo normal
    analogWrite(rojo, 170);
    analogWrite(verde, 170);
    analogWrite(azul, 0);
    delay(1000);

    // Amarillo fuerte
    analogWrite(rojo, 255);
    analogWrite(verde, 255);
    analogWrite(azul, 0);
    delay(1000);
}
