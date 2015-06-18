#include "KeyboardEvent.h"

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
  }
}
