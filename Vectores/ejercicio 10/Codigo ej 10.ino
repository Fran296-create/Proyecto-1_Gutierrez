int buzzer = 8;
int numeros[10];

void setup() {
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
  randomSeed(analogRead(0));

  for (int i = 0; i < 10; i++) {
    numeros[i] = random(1, 11);
    Serial.println(numeros[i]);
    if (numeros[i] == 5) {
      tone(buzzer, 1000, 300);
      delay(300);
    }
  }
}

void loop() {
}