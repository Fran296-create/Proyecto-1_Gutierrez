int rojo = 7;
int verde = 5;
int azul = 6;

int colores[3][3] = {
  {122, 234, 21},
  {33, 53, 155},
  {200, 255, 12}
};

void setup() {
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(azul, OUTPUT);
}

void loop() {
  for (int i = 0; i < 3; i++) {
    analogWrite(rojo, colores[i][0]);
    analogWrite(verde, colores[i][1]);
    analogWrite(azul, colores[i][2]);
    delay(1000);
  }
}