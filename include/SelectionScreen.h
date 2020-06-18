#if !defined SELECTIONSCREENCLASS_H
#define SELECTIONSCREENCLASS_H

#include "vex.h"
#include "Button.h"

class SelectionScreen
{
  public:
    enum SelectionScreenType
    {
      Alliance,
      ConfirmCancel,
      LeftRightSide
    };

    SelectionScreen(SelectionScreenType ScreenType);
    SelectionScreen(Button *OptionButtons, int ButtonCount, std::string TitleText);

    Button* OptionButtons;
    std::string TitleText;

    std::string WaitForPress();

  private:
    int ButtonCount = 2;
};

#endif // SELECTIONSCREENCLASS_H