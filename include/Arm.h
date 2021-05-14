#if !defined ARMCLASS_H
#define ARMCLASS_H

#include "vex.h"

class Arm
{
  public:
    Arm(motor *LeftMotor, motor *RightMotor);
    Arm(motor *LeftMotor, motor *RightMotor, float GearRatio);
    Arm(motor *LeftMotor, motor *RightMotor, float GearRatio, limit *DownSwitch, limit *UpSwitch);

    float GetPosition(); // Returns the current position of the arm.
    void SetPositiion(float Degrees); // Sets the position of the arm.
    void MoveToPosition(float Degrees, float Speed = 70, bool Wait = true); // Moves the arm to the specified position.
    void Raise(float Degrees, float Speed = 70, bool Wait = true); // Raises the arm a number of degrees
    void Lower(float Degrees, float Speed = 70, bool Wait = true); // Lower the arm a number of degrees
    void StartRaise(float Speed = 70); // Start raising the arm
    void StartLower(float Speed = 70); // Start lowering the arm
    void Stop(); // Stop and hold the arm
    void Coast(); // Let the arm free fall
    void SetSpeed(float Speed); // Set the motor speeds

  private:
    motor *LeftMotor, *RightMotor;
    float GearRatio = 1; // Arm Gear:Motor Gear
    limit *DownSwitch, *UpSwitch;
};

#endif // ARMCLASS_H