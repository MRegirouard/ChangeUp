// ---- START VEXCODE CONFIGURED DEVICES ----
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Button.h"

using namespace vex;
competition Competition;
Button RedButton(40, 140, 180, 80, red);
Button BlueButton(160, 140, 180, 80, blue);
Button LeftSideButton(40, 100, 200, 80, orange, "Left Side", 20, black);
Button RightSideButton(140, 100, 200, 80, green, "Right Side", 20, black);
std::string TeamMsg = "Select Team:";
std::string Team;
std::string SideMsg = "Select Side:";
std::string Side;

void pre_auton()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  Brain.Screen.setFillColor(black);
  Brain.Screen.clearScreen();
  RedButton.Draw();
  BlueButton.Draw();
  Brain.Screen.setFont(mono30);
  Brain.Screen.printAt(240 - vexDisplayStringWidthGet(TeamMsg.c_str()) / 2, 80 - vexDisplayStringHeightGet(TeamMsg.c_str()) / 2, TeamMsg.c_str());

  while (!(RedButton.IsPressed() || BlueButton.IsPressed())) {;}

  if (RedButton.IsPressed())
  {
    Team = "Red";
  }
  else
  {
    Team = "Blue";
  }

  printf("Team: %s \n", Team.c_str());

  Brain.Screen.clearScreen();
  LeftSideButton.Draw();
  RightSideButton.Draw();
  Brain.Screen.printAt(240 - vexDisplayStringWidthGet(SideMsg.c_str()) / 2, 80 - vexDisplayStringHeightGet(SideMsg.c_str()) / 2, SideMsg.c_str());

  while (!(LeftSideButton.IsPressed() || RightSideButton.IsPressed())) {;}

  if (LeftSideButton.IsPressed())
  {
    Side = "Left";
  }
  else
  {
    Side = "Right";
  }

  printf("Side: %s \n ", Side.c_str());
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
