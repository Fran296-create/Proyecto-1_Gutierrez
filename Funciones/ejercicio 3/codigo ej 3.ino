#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  randomSeed(analogRead(0));
  lcdBienvenida();
  delay(1500);
  lcdInicioJuego();
  delay(1500);
  lcdFinJuego();
  delay(1500);
  lcdPuntuacion();
}

void loop() {
}

void lcdBienvenida() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Bienvenido");
}

void lcdInicioJuego() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Inicio de juego");
}

void lcdFinJuego() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Fin de juego");
}

void lcdPuntuacion() {
  long puntaje = random(0, 101);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Puntuacion:");
  lcd.setCursor(0, 1);
  lcd.print(puntaje);
}