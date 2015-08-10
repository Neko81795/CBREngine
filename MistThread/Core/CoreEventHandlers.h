#pragma once
#include <list>
#include "CoreEvents.h"
#include "EventHandler.h"

namespace MistThread
{
  namespace Core
  {
    class WindowEventHandler : public EventHandler<WindowEvent &>
    {
    public:
      virtual ~WindowEventHandler() {}
    };
  }
}

