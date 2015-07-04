#pragma once
#include "../../Event.h"
#include "../../../Graphics/Engines/GraphicsEngineCore.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        class DrawEvent : public Event
        {
        private:
          DrawEvent& operator=(const DrawEvent&) {}
        public:
          Graphics::Engines::GraphicsEngineCore &Graphics;

          DrawEvent(Graphics::Engines::GraphicsEngineCore &graphics) : Graphics(graphics) {}
          virtual ~DrawEvent() {}
        };
      }
    }
  }
}

