#include "PID.h"

PID::PID(float Proportional, float Integral, float Derivative)
{
  PMultiplier = Proportional;
  IMultiplier = Integral;
  DMultiplier = Derivative;
}

float PID::CalcPID(float Error)
{
  uint64_t Interval = vex::timer::systemHighResolution() - PrevCalcTime;

  Proportional = Error * PMultiplier;
  Integral += Error * Interval * IMultiplier;
  Derivative = (Error - PrevError) / Interval * DMultiplier;

  PrevError = Error;
  PrevCalcTime = vex::timer::systemHighResolution();

  return Proportional + Integral + Derivative;
}