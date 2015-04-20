#pragma once
#include <list>
#include "GraphicsEvents.h"

namespace CBREngine
{
  namespace Graphics
  {
    class RenderTargetResizedEventHandler
    {
    private:
      std::list<void(*)(RenderTargetResizedEvent)> ls;
    public:
      RenderTargetResizedEventHandler &operator+=(void(*func)(RenderTargetResizedEvent));
      RenderTargetResizedEventHandler &operator-=(void(*func)(RenderTargetResizedEvent));
      void operator()(RenderTargetResizedEvent &evnt);
    };
  }
}
