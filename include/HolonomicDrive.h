#if !defined HOLONOMICDRIVECLASS_H
#define HOLONOMICDRIVECLASS_H

#include "Wheel.h"

class HolonomicDrive
{
  public:
    HolonomicDrive(Wheel *Wheels, int WheelCount, float WheelCircumferece);
    
    Wheel *Wheels;
    int WheelCount;

    void MoveTo(int ForwardDistance, int RightDistance, int RoationDegrees);
    void SetSpeed(int ForwardSpeed, int RightSpeed, int RotationSpeed);
};

#endif // HOLONOMICDRIVECLASS_H