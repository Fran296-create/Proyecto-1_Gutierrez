#include <Adafruit_NeoPixel.h>

#define LEDS1 3
#define LEDS2 4
#define LEDS3 5
#define LEDS4 6
#define BOTON 2
#define BUZZER 8
#define NUMPIX 6

Adafruit_NeoPixel dado1a(NUMPIX, LEDS1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel dado1b(NUMPIX, LEDS2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel dado2a(NUMPIX, LEDS3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel dado2b(NUMPIX, LEDS4, NEO_GRB + NEO_KHZ800);

bool presionado = false;
int num1 = 0;
int num2 = 0;

void setup() {
    pinMode(BOTON, INPUT);
    pinMode(BUZZER, OUTPUT);
    dado1a.begin();
    dado1b.begin();
    dado2a.begin();
    dado2b.begin();
    randomSeed(analogRead(0));
}

void loop() {
    if (digitalRead(BOTON) == HIGH && !presionado) {
        presionado = true;

        // Animación de dados girando
        for (int i = 0; i < 10; i++) {
            num1 = random(1, 7);
            num2 = random(1, 7);

            // Limpiar LEDs
            dado1a.clear(); dado1b.clear(); dado2a.clear(); dado2b.clear();

            // Encender LEDs dado 1
            for (int j = 0; j < num1; j++) {
                dado1a.setPixelColor(j, dado1a.Color(0,0,255));
                dado1b.setPixelColor(j, dado1b.Color(0,0,255));
            }
            // Encender LEDs dado 2
            for (int j = 0; j < num2; j++) {
                dado2a.setPixelColor(j, dado2a.Color(0,0,255));
                dado2b.setPixelColor(j, dado2b.Color(0,0,255));
            }

            dado1a.show(); dado1b.show(); dado2a.show(); dado2b.show();
            delay(150);
        }

        // Mostrar puntos reales de dado 1
        dado1a.clear(); dado1b.clear();
        if(num1 >= 1) { dado1a.setPixelColor(0, dado1a.Color(0,0,255)); dado1b.setPixelColor(0, dado1b.Color(0,0,255)); }
        if(num1 >= 2) { dado1a.setPixelColor(5, dado1a.Color(0,0,255)); dado1b.setPixelColor(5, dado1b.Color(0,0,255)); }
        if(num1 >= 3) { dado1a.setPixelColor(2, dado1a.Color(0,0,255)); dado1b.setPixelColor(2, dado1b.Color(0,0,255)); }
        if(num1 >= 4) { dado1a.setPixelColor(3, dado1a.Color(0,0,255)); dado1b.setPixelColor(3, dado1b.Color(0,0,255)); }
        if(num1 == 5) { dado1a.setPixelColor(1, dado1a.Color(0,0,255)); dado1b.setPixelColor(1, dado1b.Color(0,0,255)); }
        if(num1 == 6) { dado1a.setPixelColor(4, dado1a.Color(0,0,255)); dado1b.setPixelColor(4, dado1b.Color(0,0,255)); }

        // Mostrar puntos reales de dado 2
        dado2a.clear(); dado2b.clear();
        if(num2 >= 1) { dado2a.setPixelColor(0, dado2a.Color(0,0,255)); dado2b.setPixelColor(0, dado2b.Color(0,0,255)); }
        if(num2 >= 2) { dado2a.setPixelColor(5, dado2a.Color(0,0,255)); dado2b.setPixelColor(5, dado2b.Color(0,0,255)); }
        if(num2 >= 3) { dado2a.setPixelColor(2, dado2a.Color(0,0,255)); dado2b.setPixelColor(2, dado2b.Color(0,0,255)); }
        if(num2 >= 4) { dado2a.setPixelColor(3, dado2a.Color(0,0,255)); dado2b.setPixelColor(3, dado2b.Color(0,0,255)); }
        if(num2 == 5) { dado2a.setPixelColor(1, dado2a.Color(0,0,255)); dado2b.setPixelColor(1, dado2b.Color(0,0,255)); }
        if(num2 == 6) { dado2a.setPixelColor(4, dado2a.Color(0,0,255)); dado2b.setPixelColor(4, dado2b.Color(0,0,255)); }

        dado1a.show(); dado1b.show(); dado2a.show(); dado2b.show();

        // Revisar si ganó
        if (num1 + num2 == 7) {
            for (int k = 0; k < 6; k++) {
                for (int j = 0; j < NUMPIX; j++) {
                    dado1a.setPixelColor(j, dado1a.Color(255,0,0));
                    dado1b.setPixelColor(j, dado1b.Color(255,0,0));
                    dado2a.setPixelColor(j, dado2a.Color(255,0,0));
                    dado2b.setPixelColor(j, dado2b.Color(255,0,0));
                }
                dado1a.show(); dado1b.show(); dado2a.show(); dado2b.show();
                tone(BUZZER, 1000);
                delay(200);

                for (int j = 0; j < NUMPIX; j++) {
                    dado1a.setPixelColor(j, dado1a.Color(0,0,0));
                    dado1b.setPixelColor(j, dado1b.Color(0,0,0));
                    dado2a.setPixelColor(j, dado2a.Color(0,0,0));
                    dado2b.setPixelColor(j, dado2b.Color(0,0,0));
                }
                dado1a.show(); dado1b.show(); dado2a.show(); dado2b.show();
                noTone(BUZZER);
                delay(200);
            }
        }
    }

    if (digitalRead(BOTON) == LOW) {
        presionado = false;
    }
}