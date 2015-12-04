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

        void TransformComponent::InitializeFromXML(const IO::XML::XMLElement & element)
        {
          Component::InitializeFromXML(element);

          SetZLayer(element.GetAttributeValueByName("ZLayer", 0.0f));
          Position = element.GetAttributeValueByName<Vector2>("Position");
          Scale = element.GetAttributeValueByName("Scale", Size2F(1,1));
          Rotation = element.GetAttributeValueByName("Rotation", 0.0f);
        }

        void TransformComponent::PopulateXML(IO::XML::XMLElement & element) const
        {
          Component::PopulateXML(element);

          std::stringstream str; 
          str << ZLayer;
          element.SetAttribute("ZLayer", str.str());

          str = std::stringstream(); //reset the stream
          str << Position;
          element.SetAttribute("Position", str.str());

          str = std::stringstream(); //reset the stream
          str << Scale;
          element.SetAttribute("Scale", str.str());

          str = std::stringstream(); //reset the stream
          str << Rotation;
          element.SetAttribute("Rotation", str.str());
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
