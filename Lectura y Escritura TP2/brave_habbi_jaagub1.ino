#define ledr 9
#define ledg 11
#define ledb 10
#define led2r 2
#define led2g 7
#define led2b 4
#define led3r 3
#define led3g 6
#define led3b 5
#define potTiempo A0
#define potRojo A1
#define potAzul A2
#define potVerde A3
#define buzzer 12
#define boton 8

bool sistemaActivo = true;
bool estadoAnterior = HIGH;

void setup() {
  pinMode(ledr, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledb, OUTPUT);
  
  pinMode(led2r, OUTPUT);
  pinMode(led2g, OUTPUT);
  pinMode(led2b, OUTPUT);
  
  pinMode(led3r, OUTPUT);
  pinMode(led3g, OUTPUT);
  pinMode(led3b, OUTPUT);

  pinMode(buzzer, OUTPUT);
  pinMode(boton, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  bool estadoActual = digitalRead(boton);
  if (estadoActual == LOW && estadoAnterior == HIGH) {
    sistemaActivo = !sistemaActivo;
    delay(200);
  }
  estadoAnterior = estadoActual;

  if (sistemaActivo) {
    int valorTiempo = analogRead(potTiempo);
    int valorRojo = analogRead(potRojo);
    int valorAzul = analogRead(potAzul);
    int valorVerde = analogRead(potVerde);

    int espera = map(valorTiempo, 0, 1023, 0, 3000);
    float tiempoSegundos = espera / 1000.0;
    int rojo = map(valorRojo, 0, 1023, 0, 255);
    int azul = map(valorAzul, 0, 1023, 0, 255);
    int verde = map(valorVerde, 0, 1023, 0, 255);

    Serial.print("Tiempo: ");
    Serial.println(tiempoSegundos);
    Serial.print("R: ");
    Serial.println(rojo);
    Serial.print("G: ");
    Serial.println(verde);
    Serial.print("B: ");
    Serial.println(azul);
    Serial.println("-------------");

    // LED 1
    analogWrite(ledr, rojo);
    analogWrite(ledg, verde);
    analogWrite(ledb, azul);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(espera);
    analogWrite(ledr, 0);
    analogWrite(ledg, 0);
    analogWrite(ledb, 0);

    // LED 2
    analogWrite(led2r, rojo);
    analogWrite(led2g, verde);
    analogWrite(led2b, azul);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(espera);
    analogWrite(led2r, 0);
    analogWrite(led2g, 0);
    analogWrite(led2b, 0);

    // LED 3
    analogWrite(led3r, rojo);
    analogWrite(led3g, verde);
    analogWrite(led3b, azul);
    digitalWrite(buzzer, HIGH);
    delay(100);
    digitalWrite(buzzer, LOW);
    delay(espera);
    analogWrite(led3r, 0);
    analogWrite(led3g, 0);
    analogWrite(led3b, 0);
  } else {
    Serial.println("Pausa...");
    delay(500);
  }
}
