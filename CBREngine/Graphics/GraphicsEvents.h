#pragma once
#include "../Core/Event.h"

namespace CBREngine
{
  namespace Graphics
  {
    namespace Engines
    {
      class GraphicsEngineCore;
    }
    class RenderTargetResizedEvent : public CBREngine::Core::Event
    {
    private:
      void operator=(RenderTargetResizedEvent &evnt);
    public:
      Engines::GraphicsEngineCore &Engine;
      RenderTargetResizedEvent(Engines::GraphicsEngineCore &engine) :  Engine(engine) {}
    };
  }
}
