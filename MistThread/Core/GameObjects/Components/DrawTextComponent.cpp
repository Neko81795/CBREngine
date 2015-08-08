#include "DrawTextComponent.h"
#include "../GameObject.h"
#include "../Space.h"
#include "../../Game.h"
#include <sstream>

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        void DrawTextComponent::Draw(DrawEvent * drawEvent)
        {
          drawEvent->Graphics.DrawString(Text, Font, Transform->Position * 32, Color, Transform->Rotation, Transform->GetZLayer());
        }

        void DrawTextComponent::Initialize()
        {
          Transform = static_cast<TransformComponent*>(Owner.GetComponentByName("Transform"));

          Owner.AttachEventHandler(
            "Draw",
            [](void * obj, Event* event) { static_cast<DrawTextComponent *>(obj)->Draw(static_cast<DrawEvent *>(event)); },
            this);
        }

        void DrawTextComponent::InitializeFromXML(IO::XML::XMLElement & element)
        {
          Component::InitializeFromXML(element);

          Text = element.GetAttributeByName("Text").Value;
          
          std::stringstream str(element.GetAttributeByName("Color").Value);
          str >> Color;

          str << element.GetAttributeByName("Font").Value;
          str >> Font;
        }

        //! this is unsafe
        void DrawTextComponent::PopulateXML(IO::XML::XMLElement & element) const
        {
          Component::PopulateXML(element);

          std::stringstream str;
          str << Text;
          //todo make this safe
          element.SetAttribute("Text", str.str());//! this is unsafe (Could invalidate XML) if "s are present

          str = std::stringstream(); //reset the stream
          str << Color;
          element.SetAttribute("Color", str.str());

          str = std::stringstream(); //reset the stream
          str << Font;
          element.SetAttribute("Font", str.str());
        }

        DrawTextComponent::DrawTextComponent(GameObjects::GameObjectBase *owner) : Component(owner, "Transform"), Font(owner->Game.Graphics->GetDefaultTextFormat())
        {
          Name = "DrawText";
        }

        DrawTextComponent::~DrawTextComponent()
        {}
      }
    }
  }
}
