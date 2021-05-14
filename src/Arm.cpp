#include "Arm.h"

Arm::Arm(motor *LeftMotor, motor *RightMotor)
{
  this->LeftMotor = LeftMotor;
  this->RightMotor = RightMotor;
}

Arm::Arm(motor *LeftMotor, motor *RightMotor, float GearRatio)
{
  this->LeftMotor = LeftMotor;
  this->RightMotor = RightMotor;
  this->GearRatio = GearRatio;
}

Arm::Arm(motor *LeftMotor, motor *RightMotor, float GearRatio, limit *DownSwitch, limit *UpSwitch)
{
  this->LeftMotor = LeftMotor;
  this->RightMotor = RightMotor;
  this->GearRatio = GearRatio;
  this->DownSwitch = DownSwitch;
  this->UpSwitch = UpSwitch;
}

float Arm::GetPosition()
{
  const float LeftPos = LeftMotor->position(deg) / GearRatio;
  const float RightPos = RightMotor->position(deg) / GearRatio;
  return (LeftPos + RightPos) / 2;
}

void Arm::SetPositiion(float Position)
{
  LeftMotor->setPosition(Position * GearRatio, deg);
  RightMotor->setPosition(Position * GearRatio, deg);
}

void Arm::MoveToPosition(float Position, float Speed, bool Wait)
{
  LeftMotor->spinTo(Position * GearRatio, deg, false);
  RightMotor->spinTo(Position * GearRatio, deg, false);
  while (Wait && (LeftMotor->isSpinning() || RightMotor->isSpinning()));
}

void Arm::Raise(float Degrees, float Speed, bool Wait)
{
  MoveToPosition(Degrees + GetPosition(), Speed, Wait);
}

void Arm::Lower(float Degrees, float Speed, bool Wait)
{
  Raise(-Degrees, Speed, Wait);
}

void Arm::StartRaise(float Speed)
{
  LeftMotor->setVelocity(Speed, pct);
  RightMotor->setVelocity(Speed, pct);
  LeftMotor->spin(forward);
  RightMotor->spin(forward);
}

void Arm::StartLower(float Speed)
{
  LeftMotor->setVelocity(Speed, pct);
  RightMotor->setVelocity(Speed, pct);
  LeftMotor->spin(reverse);
  RightMotor->spin(reverse);
}

void Arm::Stop()
{
  SetSpeed(0);
  LeftMotor->setBrake(hold);
  RightMotor->setBrake(hold);
}

void Arm::Coast()
{
  SetSpeed(0);
  LeftMotor->setBrake(coast);
  RightMotor->setBrake(coast);
}

void Arm::SetSpeed(float Speed)
{
  LeftMotor->setVelocity(Speed, pct);
  RightMotor->setVelocity(Speed, pct);
}