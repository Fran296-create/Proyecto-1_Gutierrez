int led = 7;
int boton = 2;
int secuencia[5];
int cantidad = 5;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  for (int i = 0; i < cantidad; i++) {
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    secuencia[i] = (digitalRead(boton) == LOW) ? 1 : 0;
    delay(500);
  }

  Serial.print("Secuencia: [ ");
  for (int i = 0; i < cantidad; i++) {
    Serial.print(secuencia[i]);
    Serial.print(" ");
    secuencia[i] = 0;
  }
  Serial.println("]");
  delay(2000);
}