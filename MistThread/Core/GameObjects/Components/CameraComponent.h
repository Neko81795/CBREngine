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
        class CameraComponent : public Component
        {
        public:
          /// <summary>
          /// the number of units tall this camera viewport is
          /// </summary>
          float Size;

          CameraComponent(GameObjects::GameObjectBase * owner);

          ~CameraComponent();
        };
      }
    }
  }
}

