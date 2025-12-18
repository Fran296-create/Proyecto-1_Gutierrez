int led1 = 7;
int led2 = 6;

int secuencia1[] = {1, 0, 0, 1, 1, 0, 1, 1};
int secuencia2[] = {0, 1, 0, 1, 0, 0, 1, 0};

int longitud = sizeof(secuencia1) / sizeof(secuencia1[0]);

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  for (int i = 0; i < longitud; i++) {
    digitalWrite(led1, secuencia1[i]);
    digitalWrite(led2, secuencia2[i]);
    delay(400);
  }
}