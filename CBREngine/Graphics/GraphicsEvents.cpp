#include "GraphicsEvents.h"

namespace CBREngine
{
  namespace Graphics
  {
    void GraphicsEvent::operator=(GraphicsEvent &) {}
        
    GraphicsEvent::GraphicsEvent(Engines::GraphicsEngineCore & graphics)
    {
      Graphics = &graphics;
    }
  }
}
