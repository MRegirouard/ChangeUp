#include "SelectionScreen.h"

SelectionScreen::SelectionScreen(SelectionScreenType ScreenType)
{
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

std::string SelectionScreen::WaitForPress()
{
  for (int B = 0; B < ButtonCount; B++)
    OptionButtons[B].Draw();

  Brain.Screen.setFont(mono30);
  Brain.Screen.setPenColor(white);
  int TextX = 240 - vexDisplayStringWidthGet(TitleText.c_str()) / 2;
  int TextY = 40 - vexDisplayStringHeightGet(TitleText.c_str()) / 2;
  Brain.Screen.printAt(TextX, TextY, TitleText.c_str());

  while (true)
  {
    while (Brain.Screen.pressing())
    {
      for (int B = 0; B < ButtonCount; B++)
      {
        if (OptionButtons[B].IsPressed())
        {
          return OptionButtons[B].Text;
        }
      }
    }
  }
}