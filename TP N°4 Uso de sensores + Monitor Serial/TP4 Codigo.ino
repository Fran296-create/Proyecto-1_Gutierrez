#define TMP_PIN   A0
#define LDR_PIN   A1
#define LED_R     9
#define LED_G     10
#define LED_B     11

void setup() {
  Serial.begin(9600);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  apagarLEDs();
}

void loop() {
  int lecturaTemp = analogRead(TMP_PIN);
  float voltaje = lecturaTemp * (5.0 / 1023.0);
  float tempC = (voltaje - 0.5) * 100.0;  // TMP36 fórmula

  int ldrRaw = analogRead(LDR_PIN);
  int luzPct = map(ldrRaw, 0, 1023, 100, 0);

  Serial.print("El nivel de luz actual es: ");
  Serial.print(luzPct);
  Serial.println("%");
  Serial.print("y la temperatura actual: ");
  Serial.print(tempC, 1);
  Serial.println("ºC");

  if (luzPct >= 30 && luzPct <= 70) {
    if (tempC > 90) {
      encenderLED(1, 0, 0); // Rojo
    } else if (tempC < 18) {
      encenderLED(0, 0, 1); // Azul
    } else {
      encenderLED(0, 1, 0); // Verde
    }
  } else {
    apagarLEDs();
  }

  delay(1000);
}

void encenderLED(int r, int g, int b) {
  digitalWrite(LED_R, r);
  digitalWrite(LED_G, g);
  digitalWrite(LED_B, b);
}

void apagarLEDs() {
  encenderLED(0, 0, 0);
}
