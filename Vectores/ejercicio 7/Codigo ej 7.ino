int leds[] = {3, 4, 5, 6, 7};
int cantidad = sizeof(leds) / sizeof(leds[0]);
int delayTiempo = 300;

void setup() {
  for (int i = 0; i < cantidad; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

void loop() {
  for (int i = 0; i < cantidad; i++) {
    digitalWrite(leds[i], HIGH);
    delay(delayTiempo);
    digitalWrite(leds[i], LOW);
  }
}