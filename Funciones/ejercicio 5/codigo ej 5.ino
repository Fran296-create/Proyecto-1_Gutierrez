int dadoLados;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  dadoLados = crearDado(20);
}

void loop() {
  int resultado = tirarDado(dadoLados);
  Serial.print("Resultado: ");
  Serial.println(resultado);
  delay(1000);
}

int crearDado(int lados) {
  return lados;
}

int tirarDado(int lados) {
  return random(1, lados + 1);
}