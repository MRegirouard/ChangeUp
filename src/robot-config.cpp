#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontLeft = motor(PORT11, ratio18_1, false);
motor FrontRight = motor(PORT19, ratio18_1, true);
motor BackLeft = motor(PORT12, ratio18_1, false);
motor BackRight = motor(PORT18, ratio18_1, true);
motor LeftIntake = motor(PORT1, ratio18_1, true);
motor RightIntake = motor(PORT17, ratio18_1, false);
motor LeftLift = motor(PORT2, ratio18_1, true);
motor RightLift = motor(PORT16, ratio18_1, false);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}