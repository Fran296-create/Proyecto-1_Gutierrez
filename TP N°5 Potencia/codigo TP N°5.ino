int pir = 13;
int luz = 12;
int ventilador = 11;
int sensorTemp = A0;

void setup() {
    pinMode(pir, INPUT);
    pinMode(luz, OUTPUT);
    pinMode(ventilador, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int valor = analogRead(sensorTemp);
    bool persona = digitalRead(pir) == HIGH;

    Serial.print("Temperatura (Lectura del TMP): ");
    Serial.print(valor);
    Serial.print(" | Persona detectada: ");
    Serial.println(persona ? "Sí" : "No");

    delay(500);

    if (valor > 207) {
        analogWrite(ventilador, 255);
        digitalWrite(luz, LOW);
    } 
    else if (persona) {
        digitalWrite(luz, HIGH);
        if (valor < 135) {
            analogWrite(ventilador, 50);
        } else if (valor < 145) {
            analogWrite(ventilador, 100);
        } else if (valor < 164) {
            analogWrite(ventilador, 150);
        } else {
            analogWrite(ventilador, 255);
        }
    } 
    else {
        digitalWrite(luz, LOW);
        analogWrite(ventilador, 0);
    }
}