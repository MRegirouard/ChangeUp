#include "Robot.h"

Robot::Robot(float WheelDiameter, float Width)
{ // WheelDiameter is the diameter of the omni wheels, Width is the length from wheel to diagonally opposite wheel in inches
  printf("Configuring the Robot object...\n");
  printf("Wheel diameter: %.3f inches.\n",  WheelDiameter);
  printf("Robot width: %.3f inches.\n", Width);
  WheelCircumference = M_PI * WheelDiameter; // Circumference of each wheel
  printf("Wheel circumference: %.3f inches.\n", WheelCircumference);
  RobotCircumference = M_PI * Width; // Total distance one wheel needs to travel to spin the robot 360°
  printf("Robot circumference: %.3f inches.\n", RobotCircumference);
  TurningRatio = RobotCircumference / WheelCircumference; // How many wheel degrees it takes for the robot to spin 1°
  printf("Turning ratio: %.3f.\n", TurningRatio);
  MovingRatio = (360 / WheelCircumference) * sqrt(2); // How many wheel degrees it takes to move 1 inch
  printf("Moving ratio: %.3f.\n", MovingRatio);
}

void Robot::Drive(int ForwardSpeed, int RightSpeed, int RotationSpeed)
{
  FrontLeft.setVelocity(ForwardSpeed + RightSpeed + RotationSpeed, percent);
  FrontRight.setVelocity(ForwardSpeed - RightSpeed - RotationSpeed, percent);
  BackLeft.setVelocity(ForwardSpeed - RightSpeed + RotationSpeed, percent);
  BackRight.setVelocity(ForwardSpeed + RightSpeed - RotationSpeed, percent);
  FrontLeft.spin(forward);
  FrontRight.spin(forward);
  BackLeft.spin(forward);
  BackRight.spin(forward);
}

void Robot::Move(float ForwardDistance, float RightDistance, float RotationDegrees, int Speed, bool Wait)
{
  printf("Moving robot.\n");
  printf("Forward distance: %.3f inches.\n", ForwardDistance);
  printf("Right distance: %.3f inches.\n", RightDistance);
  printf("Rotation: %.3f degrees.\n", RotationDegrees);
  printf("Movemvent speed: %i%%.\n\n", Speed);

  ForwardDistance = ForwardDistance * MovingRatio; // Calculate the robot's forward distance
  printf("Forward distnce: %.3f wheel degrees.\n", ForwardDistance);
  RightDistance = RightDistance * MovingRatio; // Calculate the robot's right distance
  printf("Right distnce: %.3f wheel degrees.\n", RightDistance);
  RotationDegrees = RotationDegrees * TurningRatio; // Calculate the robot's turning distance
  printf("Rotation: %.3f wheel degrees.\n\n", RotationDegrees);

  float FrontLeftDistance = ForwardDistance + RightDistance + RotationDegrees; // How far the each wheel will travel
  printf("Front left wheel will travel %.3f degrees.\n", FrontLeftDistance);
  float FrontRightDistance = ForwardDistance - RightDistance - RotationDegrees;
  printf("Front right wheel will travel %.3f degrees.\n", FrontRightDistance);
  float BackLeftDistance = ForwardDistance - RightDistance + RotationDegrees;
  printf("Back left wheel will travel %.3f degrees.\n", BackLeftDistance);
  float BackRightDistance = ForwardDistance + RightDistance - RotationDegrees;
  printf("Back right wheel will travel %.3f degrees.\n\n", BackRightDistance);

  float MaxDistance = fmax(fmax(fmax(FrontLeftDistance, FrontRightDistance), BackLeftDistance), BackRightDistance);
  printf("Maximum movement length: %.3f degrees.\n\n", MaxDistance);

  FrontLeft.setVelocity(fabs((FrontLeftDistance / MaxDistance) * Speed), percent); // Set the velocities
  printf("Front left wheel velocity: %.3f%%.\n", fabs((FrontLeftDistance / MaxDistance) * Speed));
  FrontRight.setVelocity(fabs((FrontRightDistance / MaxDistance) * Speed), percent);
  printf("Front right wheel velocity: %.3f%%.\n", fabs((FrontRightDistance / MaxDistance) * Speed));
  BackLeft.setVelocity(fabs((BackLeftDistance / MaxDistance) * Speed), percent);
  printf("Back left wheel velocity: %.3f%%.\n", fabs((BackLeftDistance / MaxDistance) * Speed));
  BackRight.setVelocity(fabs((BackRightDistance / MaxDistance) * Speed), percent);
  printf("Back right wheel velocity: %.3f%%.\n\n", fabs((BackRightDistance / MaxDistance) * Speed));

  FrontLeft.spinFor(forward, FrontLeftDistance, degrees, false); // Spin the motors
  printf("Front left wheel will spin for: %.3f degrees.\n", FrontLeftDistance);
  FrontRight.spinFor(forward, FrontRightDistance, degrees, false);
  printf("Front right wheel will spin for: %.3f degrees.\n", FrontRightDistance);
  BackLeft.spinFor(forward, BackLeftDistance, degrees, false);
  printf("Back left wheel will spin for: %.3f degrees.\n", BackLeftDistance);
  BackRight.spinFor(forward, BackRightDistance, degrees, Wait);
  printf("Back right wheel will spin for: %.3f degrees.\n", BackRightDistance);
  printf("Movement complete.\n\n");
}

void Robot::IMUTurn(float Degrees, int MaxSpeed)
{
  float GoalHeading = IMU.heading() + Degrees;
  float Error = GoalHeading - IMU.heading();
  int Speed = TurnPID.CalcPID(Error);

  TurnPID.Reset();

  while (Error > 5 || abs(Speed) > 15)
  { // Attempt to fix turn until within 5° and moving less than 15% speed
    Error = GoalHeading - IMU.heading();
    Speed = TurnPID.CalcPID(Error);

    if (Speed > MaxSpeed)
      Speed = MaxSpeed;
    else if (Speed < -MaxSpeed)
      Speed = -MaxSpeed;

    Drive(0, 0, Speed);
  }
}