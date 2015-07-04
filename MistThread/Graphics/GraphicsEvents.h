#pragma once
#include "../Core/Event.h"

namespace MistThread
{
  namespace Graphics
  {
    namespace Engines
    {
      class GraphicsEngineCore;
    }
    class GraphicsEvent : public MistThread::Core::Event
    {
    private:
      void operator=(GraphicsEvent &evnt);
    public:
      Engines::GraphicsEngineCore *Graphics;
      GraphicsEvent(Engines::GraphicsEngineCore &graphics);
    };
  }
}
