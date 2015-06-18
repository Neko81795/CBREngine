#include "TransformComponent.h"
#include "../GameObjectBase.h"


namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        float TransformComponent::GetZLayer() const
        {
          return ZLayer;
        }

        void TransformComponent::SetZLayer(float value)
        {
          ZLayer = value;
          if(Owner.DrawnBy)
            Owner.DrawnBy->UpdateObjectDrawOrder(&Owner);
          Owner.UpdateOwnDrawOrder();
        }

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
