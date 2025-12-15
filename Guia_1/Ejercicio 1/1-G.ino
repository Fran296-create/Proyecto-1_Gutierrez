// Boton
#define buttonPin 12

// LED1
#define led1r 6
#define led1b 4
#define led1g 5

// LED2
#define led2r 3
#define led2b 7
#define led2g 8

// LED3
#define led3r 9
#define led3b 10
#define led3g 11

int estado = 0;
bool lastButton = HIGH;

void setup(){
	pinMode(buttonPin, INPUT_PULLUP);

  	int leds[] = {led1r, led1g, led1b, led2r, led2g, led2b, led3r, led3g, led3b};
  	for (int i = 0; i < 9; i++){
    	pinMode(leds[i], OUTPUT);
  	}
}

void loop(){
  	bool buttonState = digitalRead(buttonPin);
  	if (buttonState == LOW && lastButton == HIGH) {
    	estado++;
    	if (estado > 2) estado = 0;
    		apagarTodos();
    	switch (estado){
      	case 0:
        	encenderRGB(led1r, led1g, led1b, 255, 0, 0);
        	break;
      	case 1:
        	encenderRGB(led2r, led2g, led2b, 0, 255, 255);
        	break;
      	case 2:
        	encenderRGB(led3r, led3g, led3b, 255, 255, 0);
        	break;
    	}
    	delay(200);
 	}
  	lastButton = buttonState;
}

void apagarTodos() {
  	int leds[] = {led1r, led1g, led1b, led2r, led2g, led2b, led3r, led3g, led3b};
  	for (int i = 0; i < 9; i++){
    	analogWrite(leds[i], 0);
  	}
}

void encenderRGB(int rPin, int gPin, int bPin, int rVal, int gVal, int bVal){
  	analogWrite(rPin, rVal);
  	analogWrite(gPin, gVal);
  	analogWrite(bPin, bVal);
}