#include "KeyEventInfo.h"


namespace MistThread
{
  namespace Input
  {
    KeyEventInfo::KeyEventInfo(Input::Key key, Core::GameTime timePressed)
    {
      Key = key;
      TimePressed = timePressed;
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
