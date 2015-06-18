#include "KeyEventInfo.h"


namespace MistThread
{
  namespace Input
  {
    KeyEventInfo::KeyEventInfo(Input::Key key, Core::GameTime timePressed, bool pressed)
    {
      Key = key;
      TimePressed = timePressed;
      Pressed = pressed;
    }

    KeyEventInfo::KeyEventInfo(Input::Key key)
    {
      Key = key;
    }

    KeyEventInfo::~KeyEventInfo()
    {

    }
  }
}
