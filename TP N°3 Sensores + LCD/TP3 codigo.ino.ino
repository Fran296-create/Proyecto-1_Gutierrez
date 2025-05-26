#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

//Sensores
#define temperatura     A0
#define luz             A1
#define movimiento      2
#define trigger         3
#define echo            4

//Led
#define rojo            9
#define verde           10
#define azul            11

//Buzzer
#define buzzer          8

//Umbrales
#define umbral_temp         39.0
#define umbral_luz          200
#define distancia_peligro   100

void setup(){
    // Configurar pines de sensores
    pinMode(movimiento, INPUT);
    pinMode(trigger, OUTPUT);
    pinMode(echo, INPUT);

    // Pines de salida
    pinMode(rojo, OUTPUT);
    pinMode(verde, OUTPUT);
    pinMode(azul, OUTPUT);
    pinMode(buzzer, OUTPUT);

    // Iniciar LCD
    lcd.begin(16, 2);
    lcd.backlight();

    // Apagar luces y buzzer al inicio
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(azul, LOW);
    digitalWrite(buzzer, LOW);

    // Comunicación Serial
    Serial.begin(9600);
}

void loop(){
  	// Leer sensores
    int valorLuz = analogRead(luz);
    int valorTempRaw = analogRead(temperatura);
    float tempC = (valorTempRaw * 5.0 / 1023.0) * 100.0;
    int valorMovimiento = digitalRead(movimiento);

    // Medir distancia
    digitalWrite(trigger, LOW);
    delayMicroseconds(2);
    digitalWrite(trigger, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    long duracion = pulseIn(echo, HIGH);
    int distancia = duracion * 0.034 / 2;

    // Limpiar estado
    apagarLuces();
    digitalWrite(buzzer, LOW);

    // Activar solo si está oscuro
    if (valorLuz < umbral_luz) {

        if (tempC > umbral_temp) {
            digitalWrite(rojo, HIGH);
            digitalWrite(buzzer, HIGH);
            delay(300);
            digitalWrite(buzzer, LOW);
        } 
        else if (valorMovimiento == HIGH) {
            digitalWrite(rojo, HIGH);
            digitalWrite(verde, HIGH);  // Rojo + Verde = Amarillo
            digitalWrite(buzzer, HIGH);
            delay(200);
            digitalWrite(buzzer, LOW);
        } 
        else if (distancia < distancia_peligro) {
            digitalWrite(rojo, HIGH);
            for (int i = 0; i < 3; i++) {
                digitalWrite(buzzer, HIGH);
                delay(100);
                digitalWrite(buzzer, LOW);
                delay(100);
            }
        }

    } else {
        // De día, solo advertencia si se acercan mucho
        if (distancia < distancia_peligro) {
            digitalWrite(rojo, HIGH);
            for (int i = 0; i < 2; i++) {
                digitalWrite(buzzer, HIGH);
                delay(100);
                digitalWrite(buzzer, LOW);
                delay(100);
            }
        }
    }

    // LCD y Serial
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("T:"); lcd.print(tempC);
    lcd.print("C L:"); lcd.print(valorLuz);

    lcd.setCursor(0, 1);
    lcd.print("D:"); lcd.print(distancia);
    lcd.print("cm M:"); lcd.print(valorMovimiento);

    Serial.print("Temperatura: "); Serial.print(tempC); Serial.println(" C");
    Serial.print("Luz: "); Serial.println(valorLuz);
    Serial.print("Distancia: "); Serial.print(distancia); Serial.println(" cm");
    Serial.print("Movimiento: "); Serial.println(valorMovimiento);
    Serial.println("------------------------");

    delay(500);

}

void apagarLuces() {
    digitalWrite(rojo, LOW);
    digitalWrite(verde, LOW);
    digitalWrite(azul, LOW);
}