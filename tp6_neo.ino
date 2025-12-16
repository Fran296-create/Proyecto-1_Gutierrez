#define SIG 2        // Ultrasonico 3 pines
#define PIR 3        // Sensor movimiento
#define BOTON 4

#define BUZZER 8

#define ROJO 9
#define AZUL 10
#define VERDE 11

bool alarmaActiva = false;
bool ultimoEstadoBoton = HIGH;

long duracion;
int distancia;

void setup() {
  pinMode(SIG, OUTPUT);

  pinMode(PIR, INPUT);
  pinMode(BOTON, INPUT_PULLUP);

  pinMode(ROJO, OUTPUT);
  pinMode(VERDE, OUTPUT);
  pinMode(AZUL, OUTPUT);

  pinMode(BUZZER, OUTPUT);

  Serial.begin(9600);
}

void loop() {

 
  bool estadoBoton = digitalRead(BOTON);

  if (estadoBoton == LOW && ultimoEstadoBoton == HIGH) {
    alarmaActiva = !alarmaActiva;
    delay(300); 
  }
  ultimoEstadoBoton = estadoBoton;

  
  pinMode(SIG, OUTPUT);
  digitalWrite(SIG, LOW);
  delayMicroseconds(2);

  digitalWrite(SIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(SIG, LOW);

  pinMode(SIG, INPUT);
  duracion = pulseIn(SIG, HIGH);
  distancia = duracion * 0.034 / 2;

  
  bool movimiento = digitalRead(PIR);

 
 Serial.print("Distancia actual del objeto: ");
  Serial.print(distancia);
  Serial.print(" cm | Alarma: ");

  if (alarmaActiva) {
    Serial.println("Activada");
  } else {
    Serial.println("Desactivada");
  }

  if (!alarmaActiva) {
    if (movimiento) {
      Serial.println("No existe movimiento detectado: falso");//hay movimiento
    } else {
      Serial.println("No existe movimiento detectado: verdadero");// no hay movimiento
    }
  }

 
  if (!alarmaActiva) {
   
    digitalWrite(AZUL, HIGH);
    digitalWrite(ROJO, LOW);
    digitalWrite(VERDE, LOW);
    digitalWrite(BUZZER, LOW);

    if (movimiento) {
      // Amarillo
      digitalWrite(ROJO, HIGH);
      digitalWrite(VERDE, HIGH);
      digitalWrite(AZUL, LOW);
    }

    delay(200);

  } else {
    //  Alarma activada

    if (distancia > 150) {
      //  Estado 1: Seguro
      digitalWrite(VERDE, HIGH);
      digitalWrite(ROJO, LOW);
      digitalWrite(AZUL, LOW);
      digitalWrite(BUZZER, LOW);
      delay(200);

    } else if (distancia >= 50 && distancia <= 150) {
      //  Estado 2: Precaución
      digitalWrite(ROJO, HIGH);
      digitalWrite(VERDE, HIGH);
      digitalWrite(AZUL, LOW);

      // Buzzer lento
      digitalWrite(BUZZER, HIGH);
      delay(100);
      digitalWrite(BUZZER, LOW);
      delay(400);

    } else {
      //  Estado 3: Peligro
      digitalWrite(ROJO, HIGH);
      digitalWrite(VERDE, LOW);
      digitalWrite(AZUL, LOW);

      // Buzzer rápido
      digitalWrite(BUZZER, HIGH);
      delay(50);
      digitalWrite(BUZZER, LOW);
      delay(50);
    }
  }
}