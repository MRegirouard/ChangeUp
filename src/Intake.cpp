#include "Intake.h"

Intake::Intake(motor *LeftMotor, motor *RightMotor)
{
  this->LeftMotor = LeftMotor;
  this->RightMotor = RightMotor;
}

Intake::Intake(motor *LeftMotor, motor *RightMotor, float GearRatio)
{
  this->LeftMotor = LeftMotor;
  this->RightMotor = RightMotor;
  this->GearRatio = GearRatio;
}

Intake::Intake(motor *LeftMotor, motor *RightMotor, float GearRatio, limit *ObjSwitch)
{
  this->LeftMotor = LeftMotor;
  this->RightMotor = RightMotor;
  this->GearRatio = GearRatio;
  this->ObjSwitch = ObjSwitch;
}

void Intake::SpinIn(float Rotations, float Speed, bool Wait)
{
  SetSpeed(Speed);
  LeftMotor->spinTo(Rotations * GearRatio, rev, false);
  RightMotor->spinTo(Rotations * GearRatio, rev, false);
  while (Wait && (LeftMotor->isSpinning() || RightMotor->isSpinning()));
}

void Intake::SpinOut(float Rotations, float Speed, bool Wait)
{
  SpinIn(-Rotations, Speed, Wait);
}

void Intake::StartSpinIn(float Speed)
{
  SetSpeed(Speed);
  LeftMotor->spin(forward);
  RightMotor->spin(forward);
}

void Intake::StartSpinOut(float Speed)
{
  SetSpeed(Speed);
  LeftMotor->spin(reverse);
  RightMotor->spin(reverse);
}

void Intake::Stop()
{
  SetSpeed(0);
  LeftMotor->setBrake(hold);
  RightMotor->setBrake(hold);
}

void Intake::SetSpeed(float Speed)
{
  LeftMotor->setVelocity(Speed, pct);
  RightMotor->setVelocity(Speed, pct);
}