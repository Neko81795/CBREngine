#include "GraphicsEvents.h"

namespace MistThread
{
  namespace Graphics
  {
    void GraphicsEvent::operator=(GraphicsEvent &) {}
        
    GraphicsEvent::GraphicsEvent(Engines::GraphicsEngineCore * graphics)
    {
      Graphics = graphics;
    }
  }
}
