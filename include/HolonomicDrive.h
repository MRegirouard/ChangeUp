#if !defined HOLONOMICDRIVECLASS_H
#define HOLONOMICDRIVECLASS_H

#include "Wheel.h"
#include "AngleConversions.h"

class HolonomicDrive
{
  public:
    HolonomicDrive(Wheel *Wheels, int WheelCount, float DriveDiameter);
    
    Wheel *Wheels;
    int WheelCount;

    void MoveTo(int ForwardDistance, int RightDistance, int RoationDegrees);
    void SetSpeed(int ForwardSpeed, int RightSpeed, int RotationSpeed);
    void UpdatePosition();
    void ResetPosition();
    double Forward, Right, Rotation;

  private:
    float Circumference;
};

#endif // HOLONOMICDRIVECLASS_H