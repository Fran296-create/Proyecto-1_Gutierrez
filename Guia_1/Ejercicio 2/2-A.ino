void setup() {
  pinMode(3, OUTPUT);
}

void loop() {
  analogWrite(3, 51);  // Intensidad (baja)
  delay(1000);

  analogWrite(3, 102);
  delay(1000);

  analogWrite(3, 153); // Intensidad (media)
  delay(1000);

  analogWrite(3, 204);
  delay(1000);

  analogWrite(3, 255); // Intensidad 5 (máxima)
  delay(1000);

  analogWrite(3, 0);   // Apagar el LED
  delay(1000);
}
