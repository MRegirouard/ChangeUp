#if !defined BUTTONCLASS_H
#define BUTTONCLASS_H

#include "vex.h"

class Button
{
  public:
    Button(); // Default constructor
    Button(int XPos, int YPos, int Width, int Height, color Color, std::string Text, int TextSize, color TextColor); // Button with text
    Button(int XPos, int YPos, int Width, int Height, color Color); // Button without text
    void Draw(); // Draw the button
    void Move(int XPos, int YPos); // Move the button
    void ChangeText(std::string Text); // Chagne the text
    bool IsPressed(); // Check if the button is pressed
    int XPos, YPos, Width, Height;
    color Color, TextColor;
    std::string Text;
    fontType Font;
  private:
    void CalcTextLocation();
    int TextX, TextY;
};

#endif // BUTTONCLASS_H