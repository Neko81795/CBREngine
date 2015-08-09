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

          std::stringstream str(element.GetAttributeByName("ZLayer").Value);
          str >> ZLayer;
          SetZLayer(ZLayer);
          str = std::stringstream();

          str << element.GetAttributeByName("Position").Value;
          str >> Position;

          str = std::stringstream(element.GetAttributeByName("Scale").Value);
          str >> Scale;

          str = std::stringstream(element.GetAttributeByName("Rotation").Value);
          str >> Rotation;
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
