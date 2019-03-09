#include "Wheels.h"

#define EnA 7
#define In1 6
#define In2 5
#define In3 4
#define In4 3
#define EnB 2



Wheels w;
volatile char cmd;

void setup() {
  // put your setup code here, to run once:
  w.attach(3,4,11,5,6,10);
  
  Serial.begin(9600);
  Serial.println("Forward: WAD");
  Serial.println("Back: ZXC");
  Serial.println("Stop: S");



}

void loop() {
  //w.setSpeed(200);
  w.goForward(60);
  while(Serial.available())
  {
    cmd = Serial.read();
    switch(cmd)
    {
      case 'w': w.forward(); break;
      case 'x': w.back(); break;
      case 'a': w.forwardLeft(); break;
      case 'd': w.forwardRight(); break;
      case 'z': w.backLeft(); break;
      case 'c': w.backRight(); break;
      case 's': w.stop(); break;
      case '1': w.setSpeedLeft(75); break;
      case '2': w.setSpeedLeft(200); break;
      case '9': w.setSpeedRight(75); break;
      case '0': w.setSpeedRight(200); break;
      case '5': w.setSpeed(100); break;
    }
  }
}
