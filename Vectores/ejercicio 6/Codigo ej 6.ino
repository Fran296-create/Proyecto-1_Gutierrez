int numeros[] = {2, 6, 10, 11};
int longitud = sizeof(numeros) / sizeof(numeros[0]);

void setup() {
  Serial.begin(9600);
  mostrarMultiplos(numeros, longitud, 5);
}

void loop() {
}

void mostrarMultiplos(int v[], int n, int cantidad) {
  for (int i = 0; i < n; i++) {
    Serial.print("Multiplos de ");
    Serial.print(v[i]);
    Serial.print(": ");
    for (int j = 1; j <= cantidad; j++) {
      Serial.print(v[i] * j);
      Serial.print(" ");
    }
    Serial.println();
  }
}