#include "TransformComponent.h"
#include "../GameObjectBase.h"
#include <sstream>

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

        void TransformComponent::DeSerialize(const IO::XML::XMLElement & element)
        {
          Component::DeSerialize(element);

          SetZLayer(element.GetAttributeValueByName("ZLayer", 0.0f));
          Position = element.GetAttributeValueByName<Vector2>("Position");
          Scale = element.GetAttributeValueByName("Scale", Size2F(1,1));
          Rotation = element.GetAttributeValueByName("Rotation", 0.0f);
        }

        void TransformComponent::Serialize(IO::XML::XMLElement & element) const
        {
          Component::Serialize(element);

          element.SetAttribute("ZLayer", ZLayer);
          element.SetAttribute("Position", Position);
          element.SetAttribute("Scale", Scale);
          element.SetAttribute("Rotation", Rotation);
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
