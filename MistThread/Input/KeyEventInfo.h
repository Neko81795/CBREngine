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
      bool Pressed;

      KeyEventInfo(Input::Key key, Core::GameTime timePressed, bool pressed = true);
      KeyEventInfo(Input::Key key);
      ~KeyEventInfo();
    };
  }
}

