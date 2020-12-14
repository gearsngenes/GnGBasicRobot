#include "GnGBasicRobot.h"
//#include "GnGBasicRobot.CPP"

GnGBasicRobot robot1;

void setup() {
  // put your setup code here, to run once:
  robot1.setUp();
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  robot1.moveRobotForward(2000);
  Serial.println("F");
  Serial.println("B");
  robot1.moveRobotBackward(2000);
  Serial.println("R");
  robot1.moveRobotRight(2000);
  Serial.println("L");
  robot1.moveRobotLeft(2000);
  Serial.println("Stop");
  robot1.stopRobot();
  delay(2000);
  Serial.println();
}
