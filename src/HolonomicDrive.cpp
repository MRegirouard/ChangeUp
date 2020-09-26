#include "HolonomicDrive.h"

HolonomicDrive::HolonomicDrive(Wheel *Wheels, int WheelCount, float WheelCircumference)
{
  this->WheelCount = WheelCount;
}

void HolonomicDrive::MoveTo(int ForwardDistance, int RightDistance, int RoationDegrees)
{

}

void HolonomicDrive::SetSpeed(int ForwardSpeed, int RightSpeed, int RotationSpeed)
{
  float Angle = atan2(ForwardSpeed, RightSpeed) * 180 / M_PI;
  float Magnitude = sqrt(ForwardSpeed^2 + RightSpeed^2);

  for (int W = 0; W < WheelCount; W++)
  {
    float WheelRadians = Wheels[W].Angle * 180 / M_PI;
    Wheels[W].setVelocity(Magnitude * sin(Angle - WheelRadians + 90 * 180 / M_PI) + RotationSpeed, percent);
    Wheels[W].spin(forward);
  }
}