#include "SelectionScreen.h"

SelectionScreen::SelectionScreen(SelectionScreenType ScreenType)
{
  OptionButtons = new Button[2];

  if (ScreenType == SelectionScreenType::Alliance)
  {
    TitleText = "Select Alliance:";
    OptionButtons[0] = Button(30, 70, 200, 140, red, "Red", 30, black);
    OptionButtons[1] = Button(250, 70, 200, 140, blue, "Blue", 30, black);
  }
  else if (ScreenType == SelectionScreenType::ConfirmCancel)
  {
    TitleText = "Confirm:";
    OptionButtons[0] = Button(20, 180, 160, 40, red, "Cancel", 20, black);
    OptionButtons[1] = Button(300, 180, 160, 40, green, "Confirm", 20, black);
  }
  else if (ScreenType == SelectionScreenType::LeftRightSide)
  {
    TitleText = "Select Side:";
    OptionButtons[0] = Button(30, 70, 200, 140, orange, "Left", 30, black);
    OptionButtons[1] = Button(250, 70, 200, 140, green, "Right", 30, black);
  }
}

SelectionScreen::SelectionScreen(Button *OptionButtons, int ButtonCount, std::string TitleText)
{
  this->OptionButtons = OptionButtons;
  this->TitleText = TitleText;
  this->ButtonCount = ButtonCount;
}

std::string SelectionScreen::WaitForPress(bool PreClear, bool PostClear)
{
  Controller1.Screen.clearScreen();
  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("%s", TitleText.c_str());
  Controller1.Screen.newLine();
  Controller1.Screen.print("%s %s", Indicator.c_str(), OptionButtons[0].Text.c_str());
  Controller1.Screen.newLine();
  Controller1.Screen.print("  %s", OptionButtons[1].Text.c_str());

  int SelectedOption = 1; // Option1 or Option2
  int Option1 = 0;
  int Option2 = 1;

  if (PreClear)
    Brain.Screen.clearScreen();

  for (int B = 0; B < ButtonCount; B++)
    OptionButtons[B].Draw();

  Brain.Screen.setFont(mono30);
  Brain.Screen.setPenColor(white);
  Brain.Screen.setFillColor(transparent);
  int TextX = 240 - vexDisplayStringWidthGet(TitleText.c_str()) / 2;
  int TextY = 50 - vexDisplayStringHeightGet(TitleText.c_str()) / 2;
  Brain.Screen.printAt(TextX, TextY, TitleText.c_str());

  while (true)
  {
    if (Brain.Screen.pressing())
    {
      for (int B = 0; B < ButtonCount; B++)
      {
        if (OptionButtons[B].IsPressed())
        {
          while (Brain.Screen.pressing()) {;}

          if (PostClear)
            Brain.Screen.clearScreen();

          return OptionButtons[B].Text;
        }
      }
    }
    else if (Controller1.ButtonUp.pressing())
    {
      if (SelectedOption == 1 && Option1 > 0)
      {
        Option1--;
        Option2--;
        SelectedOption = 1;

        Controller1.Screen.clearScreen();
        Controller1.Screen.setCursor(1, 1);
        Controller1.Screen.print("%s", TitleText.c_str());
        Controller1.Screen.newLine();
        Controller1.Screen.print("%s %s", Indicator.c_str(), OptionButtons[Option1].Text.c_str());
        Controller1.Screen.newLine();
        Controller1.Screen.print("  %s", OptionButtons[Option2].Text.c_str());
      }
      else if (SelectedOption == 2)
      {
        Controller1.Screen.setCursor(2, 1);
        Controller1.Screen.print(Indicator.c_str());
        Controller1.Screen.newLine();
        Controller1.Screen.print(" ");
        SelectedOption = 1;
      }

      while (Controller1.ButtonUp.pressing()) {;}
    }
    else if (Controller1.ButtonDown.pressing())
    {
      if (SelectedOption == 2 && Option2 < ButtonCount - 1)
      {
        Option1++;
        Option2++;

        Controller1.Screen.clearScreen();
        Controller1.Screen.setCursor(1, 1);
        Controller1.Screen.print("%s", TitleText.c_str());
        Controller1.Screen.newLine();
        Controller1.Screen.print("  %s", OptionButtons[Option1].Text.c_str());
        Controller1.Screen.newLine();
        Controller1.Screen.print("%s %s", Indicator.c_str(), OptionButtons[Option2].Text.c_str());
      }
      else if (SelectedOption == 1)
      {
        Controller1.Screen.setCursor(2, 1);
        Controller1.Screen.print(" ");
        Controller1.Screen.setCursor(3, 1);
        Controller1.Screen.print(Indicator.c_str());
        SelectedOption = 2;
      }

      while (Controller1.ButtonDown.pressing()) {;}
    }
    else if (Controller1.ButtonA.pressing())
    {
      while (Controller1.ButtonA.pressing()) {;}

      if (PostClear)
        Brain.Screen.clearScreen();

      Controller1.Screen.clearScreen();

      if (SelectedOption == 1)
        return OptionButtons[Option1].Text;
      else if (SelectedOption == 2)
        return OptionButtons[Option2].Text;
    }
  }
}