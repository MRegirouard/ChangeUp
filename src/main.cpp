// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;
competition Competition;

void pre_auton()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
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
  
  pre_auton(); // Run the pre-autonomous function.

  // Prevent main from exiting with an infinite loop.
  while (true)
  {
    wait(100, msec);
  }
}
