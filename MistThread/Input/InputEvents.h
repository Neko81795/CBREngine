#pragma once
#include "../Core/Event.h"
#include "../Core/Vector2.h"
#include "Key.h"

namespace MistThread
{
  namespace Input
  {
    class KeyboardEvent : public Core::Event
    {
    public:
      Key Key;
      bool Pressed;

      KeyboardEvent(Input::Key key, bool pressed);
      ~KeyboardEvent();
    };

    class MouseEvent : public Core::Event
    {
    public:
      Core::Vector2 Position;
      short Wheel;
      bool LeftDown;
      bool MiddleDown;
      bool RightDown;
      bool ControlPressed;
      bool ShiftPressed;
      bool AltPressed;

      MouseEvent(const Core::Vector2 &position, bool leftDown, bool middleDown, bool rightDown, bool controlPressed, bool shiftPressed, bool altPressed, short wheel = 0);
      ~MouseEvent();
    };
  }
}

