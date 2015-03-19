#pragma once
#include <list>
#include "GraphicsEvents.h"

namespace CBREngine
{
  namespace Graphics
  {
    class WindowResizedEventHandler
    {
    private:
      std::list<void(*)(WindowResizedEvent)> ls;
    public:
      WindowResizedEventHandler &operator+=(void(*func)(WindowResizedEvent));
      WindowResizedEventHandler &operator-=(void(*func)(WindowResizedEvent));
      void operator()(WindowResizedEvent &evnt);
    };
  }
}
