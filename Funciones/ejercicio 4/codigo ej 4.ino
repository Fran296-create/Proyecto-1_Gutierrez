int led = 2;
int sensor = 3;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  prenderLuzSiMovimiento();
}

void prenderLuzSiMovimiento() {
  if (digitalRead(sensor) == HIGH) {
    digitalWrite(led, HIGH);
  } else {
    digitalWrite(led, LOW);
  }
  delay(200);
}