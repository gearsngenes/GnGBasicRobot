#ifndef GnGBasicRobot_h
#define GnGBasicRobot_h
#include "Arduino.h"
class GnGBasicRobot
{
  private:
    int Motor1In1;
    int Motor1In2;
    int PWMIn;
    int Motor2In1;
    int Motor2In2;
    int BoardAlive;
    int speedval;
    int state;


  public:
    GnGBasicRobot();
    GnGBasicRobot(int m1I1, int m1I2, int pwmpin, int m2I1, int m2I2, int spval);
    void printVals();
    void moveM1Forward();
    void moveM1Backward();
    void moveM2Backward();
    void moveM2Forward();
    void stopM1();
    void stopM2();

    void moveRobotForward(int delTime = 500);
    void moveRobotBackward(int delTime = 500);
    void moveRobotRight(int delTime = 500);
    void moveRobotLeft(int delTime = 500);
    void stopRobot();
    void processRightTurn(boolean start);//start = true means start the turn. start = false means stop the turn
    void processLeftTurn(boolean start);//start = true means start the turn. start = false means stop the turn
    void increaseSpeed();
    void decreaseSpeed();

    void setUp();
};
#endif