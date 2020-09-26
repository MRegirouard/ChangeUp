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

    SelectionScreen(SelectionScreenType ScreenType, vex::controller* Controller);
    SelectionScreen(Button *OptionButtons, int ButtonCount, std::string TitleText, vex::controller* Controller);

    Button* OptionButtons;
    std::string TitleText;

    std::string WaitForPress(bool PreClear = true, bool PostClear = true);

  private:
    int ButtonCount = 2;
    std::string Indicator = "-";
    vex::controller* Controller;
};

#endif // SELECTIONSCREENCLASS_H