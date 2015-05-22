#pragma once
#include <list>
#include "GraphicsEvents.h"
#include "../Core/EventHandler.h"

namespace CBREngine
{
  namespace Graphics
  {
    class GraphicsEventHandler : public Core::EventHandler<GraphicsEvent &>
    {
    public:
      virtual ~GraphicsEventHandler() {}
    };
  }
}
