#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523

int buzzer = 2;

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  melodiaCumple();
  delay(2000);
  melodiaPropia();
}

void melodiaCumple() {
  int melodiaNotas[] = {NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4, NOTE_E4,
                        NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4, NOTE_F4};
  int melodiaDuracion[] = {4,4,2,2,2,1, 4,4,2,2,2,1};

  for (int i = 0; i < 12; i++) {
    int duracionNota = 1000 / melodiaDuracion[i];
    Serial.print("Nota Cumple: ");
    Serial.println(melodiaNotas[i]);
    tone(buzzer, melodiaNotas[i], duracionNota);
    delay(duracionNota * 1.3);
  }
}

void melodiaPropia() {
  int melodiaNotas[] = {
    NOTE_E4, NOTE_D4, NOTE_C4,
    NOTE_F4, NOTE_E4, NOTE_D4,
    NOTE_G4, NOTE_A4, NOTE_B4, NOTE_C5, NOTE_E4,
    NOTE_D4, NOTE_C4
  };

  int melodiaDuracion[] = {
    8,8,4,
    8,8,4,   
    8,16,16,8,8, 
    4,4
  };

  int n = sizeof(melodiaNotas) / sizeof(melodiaNotas[0]);
  for (int i = 0; i < n; i++) {
    int duracionNota = 1000 / melodiaDuracion[i];
    Serial.print("Nota Propia: ");
    Serial.println(melodiaNotas[i]);
    tone(buzzer, melodiaNotas[i], duracionNota);
    delay(duracionNota * 1.3);
  }
  delay(1000);
}
