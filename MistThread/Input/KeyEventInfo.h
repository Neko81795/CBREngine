#pragma once
#include "Key.h"
#include "../Core/GameTime.h"

namespace MistThread
{
  namespace Input
  {
    struct KeyEventInfo
    {
    public:
      Input::Key Key;
      Core::GameTime TimePressed;

      KeyEventInfo(Input::Key key, Core::GameTime timePressed);
      KeyEventInfo(Input::Key key);
      ~KeyEventInfo();
    };
  }
}

