#include "HolonomicDrive.h"

HolonomicDrive::HolonomicDrive(Wheel *Wheels, int WheelCount, float DriveDiameter)
{
  this->WheelCount = WheelCount;
  Circumference = M_PI * DriveDiameter;
}

void HolonomicDrive::MoveTo(int ForwardDistance, int RightDistance, int RoationDegrees)
{

}

void HolonomicDrive::SetSpeed(int ForwardSpeed, int RightSpeed, int RotationSpeed)
{
  float Angle = atan2(ForwardSpeed, RightSpeed) * toDeg;
  float Magnitude = sqrt(ForwardSpeed^2 + RightSpeed^2);

  for (int W = 0; W < WheelCount; W++)
  {
    Wheels[W].setVelocity(Magnitude * sin((Angle - Wheels[W].Angle + 90) * toRad) + RotationSpeed, percent);
    Wheels[W].spin(forward);
  }
}

void HolonomicDrive::UpdatePosition()
{
  float ForwardChange = 0;
  float RightChange = 0;
  float RotationChange = 0;

  for (int W = 0; W < WheelCount; W++)
  {
    ForwardChange += sin((Rotation - Wheels[W].Angle + 90) * toRad) * Wheels[W].position(rev) * Wheels[W].Circumference;
    RightChange += sin((Rotation - Wheels[W].Angle + 90) * toDeg) * Wheels[W].position(rev) * Wheels[W].Circumference;
    RotationChange += Wheels[W].position(rev) * Wheels[W].Circumference / Circumference;
    Wheels[W].resetPosition();
  }

  Forward += ForwardChange;
  Right += RightChange;
  Rotation += RotationChange;

  printf("Robot Positio: (%f in, %f in, %f°)", Forward, Right, Rotation);
}

void HolonomicDrive::ResetPosition()
{
  Forward = 0;
  Right = 0;
  Rotation = 0;
}