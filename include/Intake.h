#if !defined INTAKECLASS_H
#define INTAKEsCLASS_H

#include "vex.h"

class Intake
{
  public:
    Intake(motor *LeftMotor, motor *RightMotor);
    Intake(motor *LeftMotor, motor *RightMotor, float GearRatio);
    Intake(motor *LeftMotor, motor *RightMotor, float GearRatio, limit *ObjSwitch);

    void SpinIn(float Rotations, float Speed = 70, bool Wait = true); // Rotate the intake motors in by a number of rotations
    void SpinOut(float Rotations, float Speed = 70, bool Wait = true); // Rotate the intake motors out by a number of rotations
    void StartSpinIn(float Speed = 70); // Start spinning in the intake
    void StartSpinOut(float Speed = 70); // Start spinning out the intake
    void Stop(); // Stop spinning the intake
    void SetSpeed(float Speed); // Set the intake motor speeds

  private:
    motor *LeftMotor, *RightMotor;
    float GearRatio = 1; // Intake Gear:Motor Gear
    limit *ObjSwitch;
};

#endif // INTAKECLASS_H