#include "GraphicsEventHandlers.h"

namespace CBREngine
{
  namespace Graphics
  {
    RenderTargetResizedEventHandler &RenderTargetResizedEventHandler::operator+=(void (*func)(RenderTargetResizedEvent))
    {
      ls.push_back(func);
      return *this;
    }

    RenderTargetResizedEventHandler & RenderTargetResizedEventHandler::operator-=(void(*func)(RenderTargetResizedEvent))
    {
      ls.remove(func);
      return *this;
    }

    void RenderTargetResizedEventHandler::operator()(RenderTargetResizedEvent &evnt)
    {
      for each (void(*func)(RenderTargetResizedEvent) in ls)
      {
        func(evnt);
      }
    }
  }
}
