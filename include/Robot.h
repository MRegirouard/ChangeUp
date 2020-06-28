#if !defined ROBOTCLASS_H
#define ROBOTCLASS_H

#include "vex.h"
#include "PID.h"

class Robot
{
  public:
    Robot(float WheelDiameter, float Width); // Initailize the robot
    void Drive(int ForwardSpeed, int RightSpeed, int RotationSpeed); // Move the robot (speed)
    void Move(float ForwardDistance, float RightDistance, float RotationDegrees, int MaxSpeed = 100, bool Wait = true); // Moves a specific distance (inches / degrees)
    void IMUTurn(float RotationDegrees, int MaxSpeed = 100);
  private:
    float WheelCircumference;
    float RobotCircumference;
    float TurningRatio; // How many wheel degrees it takes to spin the robot 1 degree
    float MovingRatio; // How many wheel degrees it takes to move 1 inch

    PID TurnPID = PID(7, 5, 2);
};

#endif // ROBOTCLASS_H