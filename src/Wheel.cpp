#include  "Wheel.h"

Wheel::Wheel(int Angle, float Diameter, int32_t Port, gearSetting GearRatio, bool Reversed) : vex::motor(Port, GearRatio, Reversed)
{
  this->Angle = Angle;
  Circumference = Diameter * M_PI;
}

Wheel::Wheel(int Angle, float Diameter, int32_t Port, bool Reversed) : vex::motor(Port, ratio18_1, Reversed)
{
  this->Angle = Angle;
  Circumference = Diameter * M_PI;
}

double Wheel::Distance()
{
  return Circumference * position(degrees);
}