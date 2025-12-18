#include <Adafruit_NeoPixel.h>


#define PIN 6
#define LEDS 12

Adafruit_NeoPixel anillo(LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  anillo.begin();
  anillo.show();
  randomSeed(analogRead(0));
}

void loop() {

  
  for (int i = 0; i < LEDS; i++) {
    anillo.clear();

    if (i % 6 == 0) anillo.setPixelColor(i, 255, 0, 0);      // Rojo
    else if (i % 6 == 1) anillo.setPixelColor(i, 0, 255, 0); // Verde
    else if (i % 6 == 2) anillo.setPixelColor(i, 0, 0, 255); // Azul
    else if (i % 6 == 3) anillo.setPixelColor(i, 255, 255, 0); // Amarillo
    else if (i % 6 == 4) anillo.setPixelColor(i, 0, 255, 255); // Cyan
    else anillo.setPixelColor(i, 255, 0, 255);               // Magenta

    anillo.show();
    delay(500);
  }

  anillo.clear();
  anillo.show();
  delay(1000);

  for (int i = 0; i < LEDS; i++) {
    anillo.clear();
    anillo.setPixelColor(i, 0, 255, 0);
    anillo.show();
    delay(150);
  }


  for (int i = LEDS - 1; i >= 0; i--) {
    anillo.clear();
    anillo.setPixelColor(i, 0, 255, 0);
    anillo.show();
    delay(150);
  }

  anillo.clear();
  anillo.show();
  delay(1000);



  int r1 = random(256);
  int g1 = random(256);
  int b1 = random(256);

  int r2 = random(256);
  int g2 = random(256);
  int b2 = random(256);

 
  for (int i = 0; i < LEDS; i++) {
    if (i % 2 == 0) {
      anillo.setPixelColor(i, r1, g1, b1);
    }
  }
  anillo.show();
  delay(500);

  anillo.clear();
  anillo.show();
  delay(200);

 
  for (int i = 0; i < LEDS; i++) {
    if (i % 2 != 0) {
      anillo.setPixelColor(i, r2, g2, b2);
    }
  }
  anillo.show();
  delay(500);

  anillo.clear();
  anillo.show();
  delay(1000);
}