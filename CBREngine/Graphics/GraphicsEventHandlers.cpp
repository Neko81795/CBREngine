#include "GraphicsEventHandlers.h"

namespace CBREngine
{
  namespace Graphics
  {
    WindowResizedEventHandler &WindowResizedEventHandler::operator+=(void (*func)(WindowResizedEvent))
    {
      ls.push_back(func);
      return *this;
    }

    WindowResizedEventHandler & WindowResizedEventHandler::operator-=(void(*func)(WindowResizedEvent))
    {
      ls.remove(func);
      return *this;
    }

    void WindowResizedEventHandler::operator()(WindowResizedEvent &evnt)
    {
      for each (void(*func)(WindowResizedEvent) in ls)
      {
        func(evnt);
      }
    }
  }
}
