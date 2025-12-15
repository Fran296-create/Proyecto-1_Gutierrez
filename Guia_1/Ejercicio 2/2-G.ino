void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
  int valor = analogRead(A0);
  int frecuencia = map(valor, 0, 1023, 100, 1000);

  tone(3, frecuencia);
  delay(100);           
}
