#pragma once
#include <list>
#include "GraphicsEvents.h"
#include "../Core/EventHandler.h"

namespace MistThread
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
