#define buttonPin 2

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);

    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
}

void loop() {
  // LED Verde
  esperarSiBoton();
  digitalWrite(3, HIGH);
  delay(1000);
  digitalWrite(3, LOW);

  // LED Amarillo
  esperarSiBoton();
  digitalWrite(4, HIGH);
  delay(1000);
  digitalWrite(4, LOW);

  // LED Naranja
  esperarSiBoton();
  digitalWrite(5, HIGH);
  delay(1000);
  digitalWrite(5, LOW);

  // LED Azul
  esperarSiBoton();
  digitalWrite(6, HIGH);
  delay(1000);
  digitalWrite(6, LOW);

  // LED Rojo
  esperarSiBoton();
  digitalWrite(7, HIGH);
  delay(1000);
  digitalWrite(7, LOW);

  // LED Verde 2
  esperarSiBoton();
  digitalWrite(8, HIGH);
  delay(1000);
  digitalWrite(8, LOW);

  // LED Amarillo 2
  esperarSiBoton();
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);

  // LED Naranja 2
  esperarSiBoton();
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW);

  // LED Azul 2
  esperarSiBoton();
  digitalWrite(11, HIGH);
  delay(1000);
  digitalWrite(11, LOW);

  // LED Rojo 2
  esperarSiBoton();
  digitalWrite(12, HIGH);
  delay(1000);
  digitalWrite(12, LOW);
}
void esperarSiBoton() {
    while (digitalRead(buttonPin) == LOW) {
        delay(10);
    }
}