// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         11              
// FrontRight           motor         19              
// BackLeft             motor         12              
// BackRight            motor         18              
// LeftIntake           motor         1               
// RightIntake          motor         17              
// LeftLift             motor         2               
// RightLift            motor         16              
// Controller1          controller                    
// Controller2          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "SelectionScreen.h"

using namespace vex;
competition Competition;
bool DualController = true;

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
