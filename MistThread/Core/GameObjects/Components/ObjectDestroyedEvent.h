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
        class ObjectDestroyedEvent : public Event
        {
        private:
          ObjectDestroyedEvent& operator=(const ObjectDestroyedEvent&) {}
        public:
          GameObject* Object;

          ObjectDestroyedEvent(GameObject* object) : Object(object) {}
          virtual ~ObjectDestroyedEvent() {}
        };
      }
    }
  }
}