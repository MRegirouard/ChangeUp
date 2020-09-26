#if !defined WHEELCLASS_H
#define WHEELCLASS_H

#include "vex.h"

class Wheel: public vex::motor
{
  public:
    Wheel(int Angle, float Diameter, int32_t Port, gearSetting GearRatio = ratio18_1, bool Reversed = false);
    Wheel(int Angle, float Diameter, int32_t Port, bool Reversed);
    int Angle;
    float Circumference;
    double Distance();
};

#endif // WHEELCLASS_H
