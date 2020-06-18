#include "SelectionScreen.h"

SelectionScreen::SelectionScreen(SelectionScreenType ScreenType)
{
  if (ScreenType == SelectionScreenType::Alliance)
  {
    TitleText = "Select Alliance:";
    OptionButtons[0] = Button(30, 70, 200, 140, 0, "Red", 30, 0);
    OptionButtons[1] = Button(250, 70, 200, 140, 240, "Blue", 30, 240);
  }
  else if (ScreenType == SelectionScreenType::ConfirmCancel)
  {
    TitleText = "Confirm:";
    OptionButtons[0] = Button(20, 180, 160, 40, 0, "Cancel", 20, 120);
    OptionButtons[1] = Button(300, 180, 160, 40, 120, "Confirm", 20, 0);
  }
  else if (ScreenType == SelectionScreenType::LeftRightSide)
  {
    TitleText = "Select Side:";
    OptionButtons[0] = Button(30, 70, 200, 140, 33, "Left", 30, 132);
    OptionButtons[1] = Button(250, 70, 200, 140, 132, "Right", 30, 33);
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