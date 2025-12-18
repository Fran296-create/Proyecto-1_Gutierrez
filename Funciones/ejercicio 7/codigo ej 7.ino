int numeros[10] = { 7, 3, 10, 1, 6, 2, 9, 4, 8, 5 };

void ordenarDesc(int v[], int tam) {
  for (int i = 0; i < tam - 1; i++) {
    for (int j = i + 1; j < tam; j++) {
      if (v[i] < v[j]) {
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
      }
    }
  }
}

void setup() {
  Serial.begin(9600);
  ordenarDesc(numeros, 10);
  Serial.print("[ ");
  for (int i = 0; i < 10; i++) {
    Serial.print(numeros[i]);
    Serial.print(" ");
  }
  Serial.println("]");
}

void loop() {
}