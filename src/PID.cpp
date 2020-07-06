#include "PID.h"

PID::PID(float Proportional, float Integral, float Derivative)
{
  PMultiplier = Proportional;
  IMultiplier = Integral;
  DMultiplier = Derivative;
}

float PID::CalcPID(float Error)
{
  uint64_t Interval = vex::timer::systemHighResolution() - PrevCalcTime; // microseconds

  Proportional = Error * PMultiplier;
  Integral += Error * Interval * IMultiplier;
  Derivative = (Error - PrevError) / Interval * DMultiplier;

  PrevError = Error;
  PrevCalcTime = vex::timer::systemHighResolution();

  if (FirstLoop)
  {
    FirstLoop = false;
    return Proportional;
  }
  else
    return Proportional + Integral + Derivative;
}

void PID::Reset()
{
  FirstLoop = true;
}