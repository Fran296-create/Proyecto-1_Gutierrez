int vector[5];

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  llenarVector(vector, 5);

  Serial.print("[ ");
  for (int i = 0; i < 5; i++) {
    Serial.print(vector[i]);
    Serial.print(" ");
  }
  Serial.println("]");
}

void loop() {
}

void llenarVector(int v[], int tam) {
  for (int i = 0; i < tam; i++) {
    int n = random(0, 11) * 10;
    v[i] = n;
  }
}