#include <Joystick.h>

// Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 10;
Joystick_ Joystick;
int scale = 3;
float speedScale = 1023;

void setup() {
  // put your setup code here, to run once:
  Joystick.begin();
  //Serial.begin(9600);
}

void loop() {
  // Get raw accelerometer data for each axis
  int rawX = analogRead(A0);
  int rawY = analogRead(A1);
  int rawZ = analogRead(A2);
  
  float scaledX, scaledY, scaledZ; // Scaled values for each axis
  scaledX = mapf(rawX, 280, 400, 0, speedScale); // 3.3/5 * 1023 =~ 675
  scaledY = mapf(rawY, 280, 400, 0, speedScale);
  scaledZ = mapf(rawZ, 280, 400, 0, speedScale);

  //Serial.println(speedScale-scaledY);
  //Serial.println(scaledZ);

  Joystick.setYAxis(constrain(speedScale-scaledY, 0, 1023));
  Joystick.setXAxis(constrain(scaledZ, 0, 1023));
  delay(20);
}

// Same functionality as Arduino's standard map function, except using floats
float mapf(float x, float in_min, float in_max, float out_min, float out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
