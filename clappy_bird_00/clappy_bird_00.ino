int sensorPin = A0 ;  // define analog port A0
int value = 0;    //set value to 0
int threshold = 320;

#include <Keyboard.h>

void setup()
{
  Keyboard.begin();
}

void loop()
{
  value = analogRead(sensorPin);
  if(value > threshold){
    Keyboard.press(' ');
  }
  else {
    Keyboard.releaseAll();
  }
  delay(10);  //delay 0.01S
}
