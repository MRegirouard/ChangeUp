#include "HolonomicDrive.h"
#include "AngleConversions.h"

HolonomicDrive::HolonomicDrive(Wheel *Wheels, int WheelCount, float WheelCircumference)
{
  this->WheelCount = WheelCount;
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