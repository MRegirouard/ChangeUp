// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         11              
// FrontRight           motor         19              
// BackLeft             motor         12              
// BackRight            motor         18              
// LeftIntake           motor         13              
// RightIntake          motor         20              
// LeftLift             motor         4               
// RightLift            motor         7               
// Controller1          controller                    
// Controller2          controller                    
// Vision               vision        15              
// BallSwitch           limit         A               
// ArmDownSwitch        limit         B               
// ArmUpSwitch          limit         C               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "SelectionScreen.h"
#include "Arm.h"
#include "Intake.h"

using namespace vex;
competition Competition;
bool DualController = true;

Arm LiftArm(&LeftLift, &RightLift, 5, &ArmDownSwitch, &ArmUpSwitch);
Intake BallIntake(&LeftIntake, &RightIntake, 1, &BallSwitch);

void pre_auton()
{
  Button DualControl(30, 70, 200, 140, green, "Dual", 30, black);
  Button SingleControl(250, 70, 200, 140, orange, "Single", 30, black);
  SelectionScreen ControllerSelction(new Button[2] {DualControl, SingleControl}, 2, "Select Control Mode:");
  DualController = ControllerSelction.WaitForPress(true, true) == "Dual";
}

void autonomous()
{
  
}

void usercontrol()
{
  while (true)
  {
    if (DualController)
    {
      if (Controller2.ButtonL1.pressing())
        LiftArm.StartRaise(100);
      else if (Controller2.ButtonL2.pressing())
        LiftArm.StartLower(100);
      else
        LiftArm.Stop();

      if (Controller2.ButtonR1.pressing())
        BallIntake.StartSpinIn(100);
      else if (Controller2.ButtonR2.pressing())
        BallIntake.StartSpinOut(100);
      else
        BallIntake.Stop();
    }
    else
    {
      if (Controller1.ButtonL1.pressing())
        LiftArm.StartRaise(100);
      else if (Controller1.ButtonL2.pressing())
        LiftArm.StartLower(100);
      else
        LiftArm.Stop();

      if (Controller1.ButtonR1.pressing())
        BallIntake.StartSpinIn(100);
      else if (Controller1.ButtonR2.pressing())
        BallIntake.StartSpinOut(100);
      else
        BallIntake.Stop();
    }

    wait(20, msec); // Sleep the task for a short amount of time to prevent wasted resources.
  }
}

int main()
{
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  pre_auton(); // Run the pre-autonomous function.

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
