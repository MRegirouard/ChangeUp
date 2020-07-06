#if !defined PIDCLASS_H
#define PIDCLASS_H

#include "vex.h"

class PID
{
  public:
    PID(float Proportional, float Integral, float Derivative);
    float CalcPID(float Error);
    void Reset();

    float PMultiplier;
    float IMultiplier;
    float DMultiplier;

    float Proportional;
    float Integral;
    float Derivative;

  private:
    float PrevError;
    uint64_t PrevCalcTime;
    bool FirstLoop = true;
};

#endif // PIDCLASS_H