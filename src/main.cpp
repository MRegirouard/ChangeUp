// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// FrontLeft            motor         1               
// FrontRight           motor         2               
// BackLeft             motor         20              
// BackRight            motor         10              
// Controller1          controller                    
// IMU                  inertial      5               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Robot.h"

using namespace vex;
competition Competition;

float WheelDiameter = 3.25; // (inches)
float Width = 19; // Middle of wheel to middle of opposite wheel (inches)
Robot Robot(WheelDiameter, Width); // Setup the Robot

int ForwardSpeed;
int RightSpeed;
int RotationSpeed;

void pre_auton(void)
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
}

void autonomous(void)
{
  printf("Running autonomous...\n");
  //Robot.Move(0, 0, 90, 50, true);
  Robot.Move(0, 24, 0, 50);
  Robot.Move(50, 50, 90);
  printf("Autonomous complete.\n");
}

void usercontrol(void)
{
  printf("Running driver control...\n");

  while (true)
  {
    ForwardSpeed = Controller1.Axis2.position();
    RightSpeed = Controller1.Axis1.position();
    RotationSpeed = Controller1.Axis4.position();
    Robot.Drive(ForwardSpeed, RightSpeed, RotationSpeed);

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

int main()
{
  printf("Beginning main program...\n");

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
