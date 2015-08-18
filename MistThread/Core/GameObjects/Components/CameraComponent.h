#pragma once
#include "Component.h"
#include "../../CoreEvents.h"
#include "TransformComponent.h"

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
          friend class Space;
        private:
          /// <summary>
          /// the scale to apply to the renderer to get the camera to appear correct
          /// </summary>
          float CameraScale;
        public:
          /// <summary>
          /// the number of units tall this camera viewport is
          /// </summary>
          float Size = 20;
          TransformComponent *Transform;

          void Initialize() override;

          void WindowResized(WindowEvent * evnt);

          CameraComponent(GameObjects::GameObjectBase * owner);

          ~CameraComponent();
        };
      }
    }
  }
}

