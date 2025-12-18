int pinesSalida[] = {3, 4, 5};
int pinesEntrada[] = {6, 7};

void setup() {
  Serial.begin(9600);
  configurarPines(pinesSalida, sizeof(pinesSalida)/sizeof(pinesSalida[0]), OUTPUT);
  configurarPines(pinesEntrada, sizeof(pinesEntrada)/sizeof(pinesEntrada[0]), INPUT);
  Serial.println("Configuracion de pines completada");
}

void loop() {
}

void configurarPines(int pines[], int tam, int modo) {
  for (int i = 0; i < tam; i++) {
    pinMode(pines[i], modo);
  }
}