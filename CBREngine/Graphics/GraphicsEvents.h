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
    class GraphicsEvent : public CBREngine::Core::Event
    {
    private:
      void operator=(GraphicsEvent &evnt);
    public:
      Engines::GraphicsEngineCore *Graphics;
      GraphicsEvent(Engines::GraphicsEngineCore &graphics);
    };
  }
}
