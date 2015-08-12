#pragma once
#include "Component.h"
#include "UpdateEvent.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        class ConsoleComponent : public Component
        {
          ///////////////////////////////
          //Variables
          ///////////////////////////////
        private:
          GameObjects::Space *ConsoleSpace;
          GameObject *Console;
          bool ConsoleVisable;
          ///////////////////////////////
          //Methods
          ///////////////////////////////
        public:
          void Update(UpdateEvent * event);
          ///////////////////////////////
          //Constructors
          ///////////////////////////////
        public:
          ConsoleComponent(GameObjects::GameObjectBase *owner);
          ~ConsoleComponent();
        };
      }
    }
  }
}
