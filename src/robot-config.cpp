#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor FrontLeft = motor(PORT11, ratio18_1, false);
motor FrontRight = motor(PORT19, ratio18_1, false);
motor BackLeft = motor(PORT12, ratio18_1, false);
motor BackRight = motor(PORT18, ratio18_1, false);
motor LeftIntake = motor(PORT13, ratio18_1, true);
motor RightIntake = motor(PORT20, ratio18_1, false);
motor LeftLift = motor(PORT4, ratio36_1, true);
motor RightLift = motor(PORT7, ratio36_1, false);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
/*vex-vision-config:begin*/
vision Vision = vision (PORT15, 50);
/*vex-vision-config:end*/
limit BallSwitch = limit(Brain.ThreeWirePort.A);
limit ArmDownSwitch = limit(Brain.ThreeWirePort.B);
limit ArmUpSwitch = limit(Brain.ThreeWirePort.C);

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