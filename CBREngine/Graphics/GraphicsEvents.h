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
    class WindowResizedEvent : CBREngine::Core::Event
    {
    private:
      WindowResizedEvent();
      void operator=(WindowResizedEvent evnt);
    public:
      Engines::GraphicsEngineCore &Engine;
      WindowResizedEvent(Engines::GraphicsEngineCore &engine);
      WindowResizedEvent(const WindowResizedEvent &other);
    };
  }
}
