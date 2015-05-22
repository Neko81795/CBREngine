#pragma once
#include "../../Event.h"
#include "../../GameTime.h"
namespace CBREngine
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        class UpdateEvent : public Event
        {
        private:
          UpdateEvent& operator=(const UpdateEvent&) {}
        public:
          const Core::GameTime &GameTime;
          UpdateEvent(const Core::GameTime & gameTime) : GameTime(gameTime) {}
          virtual ~UpdateEvent() {}
        };
      }
    }
  }
}

