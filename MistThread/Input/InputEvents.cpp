#include "InputEvents.h"
#include "../Core/Vector2.h"

namespace MistThread
{
  namespace Input
  {
    KeyboardEvent::KeyboardEvent(Input::Key key, bool pressed)
    {
      Key = key;
      Pressed = pressed;
    }

    KeyboardEvent::~KeyboardEvent()
    {

    }

    MouseEvent::MouseEvent(const Core::Vector2 &position, bool leftDown, bool middleDown, bool rightDown, bool controlPressed, bool shiftPressed, bool altPressed, short wheel)
    {
      Position = position;
      LeftDown = leftDown;
      MiddleDown = middleDown;
      RightDown = rightDown;
      ControlPressed = controlPressed;
      ShiftPressed = shiftPressed;
      AltPressed = altPressed;
      Wheel = wheel;
    }

    MouseEvent::~MouseEvent()
    {

    }
  }
}
