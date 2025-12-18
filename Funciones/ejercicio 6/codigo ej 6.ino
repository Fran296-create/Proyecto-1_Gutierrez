int pines[] = {3, 4, 5, 6, 7};
int cantidad = 5;

void setup() {
  for (int i = 0; i < cantidad; i++) {
    pinMode(pines[i], OUTPUT);
  }
}

void loop() {
  encenderTodos(pines, cantidad);
  delay(800);
  apagarTodos(pines, cantidad);
  delay(800);
}

void encenderTodos(int v[], int n) {
  for (int i = 0; i < n; i++) {
    digitalWrite(v[i], HIGH);
  }
}

void apagarTodos(int v[], int n) {
  for (int i = 0; i < n; i++) {
    digitalWrite(v[i], LOW);
  }
}