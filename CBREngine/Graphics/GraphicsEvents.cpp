#include "GraphicsEvents.h"

namespace CBREngine
{
  namespace Graphics
  {
    void WindowResizedEvent::operator=(WindowResizedEvent evnt)
    {
      (void)evnt;
    }
    WindowResizedEvent::WindowResizedEvent(Engines::GraphicsEngineCore &engine) : Engine(engine) {}
    WindowResizedEvent::WindowResizedEvent(const WindowResizedEvent & other) : Engine(other.Engine) {}
  }
}
