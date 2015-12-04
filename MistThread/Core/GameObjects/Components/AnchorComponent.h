#pragma once
#include "Component.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        class AnchorComponent : public Component
        {
        public:
          AnchorComponent(GameObjectBase * owner);
          ~AnchorComponent();
        };
      }
    }
  }
}
