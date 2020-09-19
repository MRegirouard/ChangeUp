#include "Button.h"

Button::Button()
{}

Button::Button(int XPos, int YPos, int Width, int Height, color Color, std::string Text, int TextSize, color TextColor)
{
  Button(XPos, YPos, Width, Height, Color);
  this->Text = Text;
  this->TextColor = TextColor;

  switch(TextSize)
  {
    case 12:
      Font = mono12;
      break;
    case 15:
      Font = mono15;
      break;
    case 20:
      Font = mono20;
      break;
    case 30:
      Font = mono30;
      break;
    case 40:
      Font = mono40;
      break;
  }

  CalcTextLocation();
}

Button::Button(int XPos, int YPos, int Width, int Height, color Color)
{
  this->XPos = XPos;
  this->YPos = YPos;
  this->Width = Width;
  this->Height = Height;
  this->Color = Color;
}

void Button::Draw()
{
  Brain.Screen.setPenColor(Color);
  Brain.Screen.setFont(Font);
  Brain.Screen.drawRectangle(XPos, YPos, XPos + Width, YPos + Height);
  Brain.Screen.setPenColor(TextColor);
  Brain.Screen.printAt(TextX, TextY, Text.c_str());
}

void Button::Move(int XPos, int YPos)
{
  this->XPos = XPos;
  this->YPos = YPos;
  CalcTextLocation();
  Button::Draw();
}

void Button::ChangeText(std::string Text)
{
  this->Text = Text;
  CalcTextLocation();
}

bool Button::IsPressed()
{
  bool Pressed = false;

  if (Brain.Screen.pressing())
  {
    if (Brain.Screen.xPosition() > XPos && Brain.Screen.xPosition() < XPos + Width)
    {
      if (Brain.Screen.yPosition() > YPos && Brain.Screen.yPosition() < YPos + Height)
      {
        Pressed = true;
      }
    }
  }

  return Pressed;
}

void Button::CalcTextLocation()
{
  Brain.Screen.setFont(Font);
  TextX = (XPos + Width / 2) - (vexDisplayStringWidthGet(Text.c_str()) / 2);
  TextY = (YPos + Height / 2) - (vexDisplayStringHeightGet(Text.c_str()) / 2);
}