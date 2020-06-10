#if !defined BUTTONCLASS_H
#define BUTTONCLASS_H

#include "vex.h"

class Button
{
  public:
    Button(int XPos, int YPos, int Width, int Height, int Hue, std::string Text, int TextSize, int TextHue); // Initialize the button
    Button(int XPos, int YPos, int Width, int Height, int Hue);
    void Draw(); // Draw the button
    void Move(int XPos, int YPos); // Move the button
    void ChangeText(std::string Text); // Chagne the text
    bool IsPressed(); // Check if the button is pressed
    int XPos, YPos, Width, Height, Hue, TextHue;
    std::string Text;
    fontType Font;
  private:
    void CalcTextLocation();
    int TextX, TextY;
};

#endif // BUTTONCLASS_H