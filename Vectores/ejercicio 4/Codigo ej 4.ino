int led = 7;
int secuencia[] = {1, 0, 0, 1, 1, 0, 1, 1};
int longitud = sizeof(secuencia) / sizeof(secuencia[0]);

void setup() {
  pinMode(led, OUTPUT);
}

void loop() {
  for (int i = 0; i < longitud; i++) {
    digitalWrite(led, secuencia[i]);
    delay(400);
  }
}