#pragma once
#include "InputEvents.h"
#include "../Core/EventHandler.h"

namespace MistThread
{
  namespace Input
  {
    class KeyboardEventHandler : public Core::EventHandler<KeyboardEvent &>
    {
    public:
      ~KeyboardEventHandler() {}
    };

    class MouseEventHandler : public Core::EventHandler<MouseEvent &>
    {
    public:
      ~MouseEventHandler() {}
    };
  }
}

