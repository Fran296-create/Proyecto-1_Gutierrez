#define ARRAY_LEN(array) (sizeof(array) / sizeof(array[0]))
#define Db6 1245
#define Gb6 1661
#define Ab6 1865
#define B6 1976
#define Fb6 1480

const int buzzerPin = 2;

const int midi1[40][2] = {
 {Db6, 16},  {Db6, 16},  {Gb6, 16},  {Ab6, 16},  {B6, 16},
 {Ab6, 32},  {B6, 16},   {Ab6, 16},  {Gb6, 16},  {Fb6, 16},
 {Db6, 8},   {Db6, 8},   {Gb6, 16},  {Ab6, 16},  {B6, 16},
 {Ab6, 32},  {B6, 16},   {Ab6, 16},  {Gb6, 16},  {Fb6, 16},
 {Db6, 8},   {Db6, 8},   {Gb6, 16},  {Ab6, 16},  {B6, 16},
 {Ab6, 32},  {B6, 16},   {Ab6, 16},  {Gb6, 16},  {Fb6, 16},
 {Db6, 8},   {Db6, 8},   {Db6, 16},  {Db6, 16},  {Db6, 8},
 {Db6, 8},   {Db6, 16},  {Db6, 16},  {Db6, 8}
};

int cuadritosToDuration(int cuadritos) {
  return cuadritos * 11;
}

void playNote(int note, int duration) {
  if (note != 0) {
    tone(buzzerPin, note);
    delay(duration);
    noTone(buzzerPin);
  } else {
    delay(duration);
  }
  delay(cuadritosToDuration(2));
}

void playMelody(const int notes[][2], int length) {
  for (int i = 0; i < length; i++) {
    int dur = cuadritosToDuration(abs(notes[i][1]));
    playNote(notes[i][0], dur);
  }
}

void pauseBetweenLoops(int seconds) {
  delay(seconds * 1000);
}

void setup() {}

void loop() {
  playMelody(midi1, ARRAY_LEN(midi1));
  pauseBetweenLoops(3);
}