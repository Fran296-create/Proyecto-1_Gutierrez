#include <Adafruit_NeoPixel.h>
#define NP 3
#define flex A0

void setup()
{
  pinMode( NP , OUTPUT ); 
  pinmode( A0 , INPUT  );
  Serial.begin(9600);
}

void loop()
{
  int flexible = map(flex,0,180,180,0);
  
  if (flexible >= 45){
  
  }

}