#pragma once
#include "../Core/Event.h"
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
  }
}

