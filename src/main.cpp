// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Button.h"
#include "SelectionScreen.h"

using namespace vex;
competition Competition;

void pre_auton()
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  printf("Beginning button test.\n");

  Button RedButton(30, 70, 200, 140, red);
  Button BlueButton(250, 70, 200, 140, blue);
  Button LeftSideButton(30, 70, 200, 140, orange, "Left Side", 30, black);
  Button RightSideButton(250, 70, 200, 140, green, "Right Side", 30, black);
  std::string TeamMsg = "Select Team:";
  std::string Team;
  std::string SideMsg = "Select Side:";
  std::string Side;
  std::string Confirm;
  SelectionScreen AllianceSelection = SelectionScreen(SelectionScreen::Alliance);
  SelectionScreen SideSelection = SelectionScreen(SelectionScreen::LeftRightSide);
  SelectionScreen ConfirmSelection = SelectionScreen(SelectionScreen::ConfirmCancel);
  Button AllianceSelectionButtons[2] = {Button(40, 140, 180, 80, red), Button(160, 140, 180, 80, blue)};
  SelectionScreen OtherAllianceSelection = SelectionScreen(AllianceSelectionButtons, 2, "Select Team (2):");

  Brain.Screen.setFillColor(black);
  Brain.Screen.clearScreen();
  RedButton.Draw();
  BlueButton.Draw();
  Brain.Screen.setFont(mono30);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.setPenColor(white);
  Brain.Screen.printAt(240 - vexDisplayStringWidthGet(TeamMsg.c_str()) / 2, 65 - vexDisplayStringHeightGet(TeamMsg.c_str()) / 2, TeamMsg.c_str());

  while (!(RedButton.IsPressed() || BlueButton.IsPressed())) {;}

  if (RedButton.IsPressed())
  {
    Team = "Red";
  }
  else
  {
    Team = "Blue";
  }

  while(Brain.Screen.pressing()) {;}

  printf("Team: %s \n", Team.c_str());

  Brain.Screen.clearScreen();
  LeftSideButton.Draw();
  RightSideButton.Draw();
  Brain.Screen.setFont(mono30);
  Brain.Screen.setFillColor(transparent);
  Brain.Screen.setPenColor(white);
  Brain.Screen.printAt(240 - vexDisplayStringWidthGet(SideMsg.c_str()) / 2, 65 - vexDisplayStringHeightGet(SideMsg.c_str()) / 2, SideMsg.c_str());

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

  printf("Beginning selection screen test.");

  Team = AllianceSelection.WaitForPress();
  printf("Team: %s \n", Team.c_str());

  Side = SideSelection.WaitForPress();
  printf("Side: %s \n ", Side.c_str());

  Confirm = ConfirmSelection.WaitForPress();
  printf("Confirm: %s \n ", Confirm.c_str());

  Team = OtherAllianceSelection.WaitForPress(false, true);
  printf("Team: %s \n", Team.c_str());

  printf("\nTest complete.");
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
