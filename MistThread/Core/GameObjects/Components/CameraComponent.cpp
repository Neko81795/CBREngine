#include "CameraComponent.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        CameraComponent::CameraComponent(GameObjects::GameObjectBase * owner) : Component(owner, "Transform")
        {
          Name = "Camera";
        }


        CameraComponent::~CameraComponent()
        {}
      }
    }
  }
}
