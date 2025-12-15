void setup() {
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
}

void loop() {
    digitalWrite(2, 26);
    delay(500);
    digitalWrite(2, 0);

    analogWrite(3, 51);
    delay(500);
    analogWrite(3, 0);

    digitalWrite(4, 77);
    delay(500);
    digitalWrite(4, 0);

    analogWrite(5, 102);
    delay(500);
    analogWrite(5, 0);

    analogWrite(6, 128);
    delay(500);
    analogWrite(6, 0);

    analogWrite(7, 153);
    delay(500);
    analogWrite(7, 0);

    analogWrite(8, 179);
    delay(500);
    analogWrite(8, 0);

    analogWrite(9, 204);
    delay(500);
    analogWrite(9, 0);

    digitalWrite(10, 230);
    delay(500);
    digitalWrite(10, 0);

    analogWrite(11, 255);
    delay(500);
    analogWrite(11, 0);
}
