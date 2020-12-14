#include "GnGBasicRobot.h"
#include "Arduino.h"

GnGBasicRobot::GnGBasicRobot()
{
  Motor1In1 = 11;
  Motor1In2 = 12;
  PWMIn = 10;
  Motor2In1 = 9;
  Motor2In2 = 6;
  speedval = 150;
  state = 0;
}
void GnGBasicRobot::printVals()
{
  Serial.println("in printvals");
}

GnGBasicRobot::GnGBasicRobot(int m1I1, int m1I2, int pwmpin, int m2I1, int m2I2, int spval)
{
  Motor1In1 = m1I1;
  Motor1In2 = m1I2;
  PWMIn = pwmpin;
  Motor2In1 = m2I1;
  Motor2In2 = m2I2;
  speedval = spval;
  //BoardAlive = balive;
  state = 0;
}

void GnGBasicRobot::moveM1Forward()
{
  analogWrite(PWMIn, speedval);
  digitalWrite(Motor1In1, HIGH);
  digitalWrite (Motor1In2, LOW );
}


void GnGBasicRobot:: moveM1Backward() {
  analogWrite(PWMIn, speedval);
  digitalWrite(Motor1In1, LOW);
  digitalWrite (Motor1In2, HIGH);
}

void GnGBasicRobot::moveM2Backward() {
  analogWrite(PWMIn, speedval);
  digitalWrite(Motor2In1, HIGH);
  digitalWrite (Motor2In2, LOW );
}

void GnGBasicRobot::moveM2Forward() {
  analogWrite(PWMIn, speedval);
  digitalWrite(Motor2In1, LOW);
  digitalWrite (Motor2In2, HIGH);
}

void GnGBasicRobot::stopM1()
{
  digitalWrite(Motor1In1, LOW);
  digitalWrite(Motor1In2, LOW);
}

void GnGBasicRobot::stopM2()
{
  digitalWrite(Motor2In1, LOW);
  digitalWrite(Motor2In2, LOW);
}
void GnGBasicRobot::moveRobotForward(int delTime)
{
  state = 1;
  moveM1Forward();
  moveM2Forward();
  delay(delTime);
}


void GnGBasicRobot::moveRobotBackward(int delTime)
{
  state = 0;
  moveM1Backward();
  moveM2Backward();
  delay(delTime);
}


void GnGBasicRobot::moveRobotRight(int delTime)
{
  moveM1Forward();
  moveM2Backward();
  delay(delTime);
}
void GnGBasicRobot::moveRobotLeft(int delTime)
{
  moveM1Backward();
  moveM2Forward();
  delay(delTime);
}

void GnGBasicRobot::stopRobot()
{
  state = -1;
  stopM1();
  stopM2();
}

void GnGBasicRobot::processRightTurn(boolean start)
{
  if (start)
  {
    moveRobotRight();
  }
  else {
    if (state == 1) {
      moveRobotForward();
    } else if (state == 0) {
      moveRobotBackward();
    } else {
      stopRobot();
    }
  };

}
void GnGBasicRobot::processLeftTurn(boolean start)
{
  if (start)
  {
    moveRobotLeft();
  }
  else {
    if (state == 1) {
      moveRobotForward();
    } else if (state == 0) {
      moveRobotBackward();
    } else {
      stopRobot();
    }
  };

}
void GnGBasicRobot::increaseSpeed()
{
  speedval = (speedval + 10);
  if (speedval >= 255) {
    speedval = 255;
  }
  Serial.print("Speed: "); Serial.println(speedval);
}
void GnGBasicRobot::decreaseSpeed()
{
  speedval = (speedval - 10);
  if (speedval <= 10) {
    speedval = 0;
  }
  Serial.print("Speed: "); Serial.println(speedval);
}

void GnGBasicRobot::setUp() {
  pinMode(Motor1In1, OUTPUT);
  pinMode(Motor1In2, OUTPUT);
  pinMode(Motor2In1, OUTPUT);
  pinMode(Motor2In2, OUTPUT);
  pinMode(PWMIn, OUTPUT);
}