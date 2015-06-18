#pragma once
#include "KeyboardEvent.h"
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
  }
}

