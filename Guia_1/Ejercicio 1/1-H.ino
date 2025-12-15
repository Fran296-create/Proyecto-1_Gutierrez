#define buttonPin 2

#define ledR 3
#define ledG 7
#define ledB 4

int estado = 0;
bool lastButton = HIGH;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledR, OUTPUT);
  pinMode(ledG, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButton == HIGH) {
    estado++;
    if (estado > 6) estado = 0;

    cambiarColor(estado);
    delay(200);
  }

  lastButton = buttonState;
}

void cambiarColor(int color) {
  switch (color) {
    case 0: setColor(255, 0, 0);   break;
    case 1: setColor(0, 255, 255); break;
    case 2: setColor(0, 255, 0);   break;
    case 3: setColor(255, 0, 255); break;
    case 4: setColor(0, 0, 255);   break;
    case 5: setColor(255, 255, 255); break;
    case 6: setColor(255, 255, 0); break;
  }
}

void setColor(int r, int g, int b) {
  analogWrite(ledR, r);
  analogWrite(ledG, g);
  analogWrite(ledB, b);
}
