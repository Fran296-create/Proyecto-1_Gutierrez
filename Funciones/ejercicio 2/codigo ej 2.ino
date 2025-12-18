int trig = 3;
int echo = 5;

void setup() {
  Serial.begin(9600);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

void loop() {
  long distancia = medirDistancia();
  Serial.println(distancia);
  delay(500);
}

long medirDistancia() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  long duracion = pulseIn(echo, HIGH);
  long cm = duracion * 0.034 / 2;
  return cm;
}