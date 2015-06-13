#include "TransformComponent.h"


namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        TransformComponent::TransformComponent(GameObjects::GameObjectBase *owner) : Component(owner)
        {
          Scale.Height = 1;
          Scale.Width = 1;
          Name = "Transform";
        }

        TransformComponent::~TransformComponent()
        {
        }
      }
    }
  }
}
