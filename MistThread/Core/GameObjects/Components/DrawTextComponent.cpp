#include "DrawTextComponent.h"
#include "Core/GameObjects/GameObject.h"
#include "Core/GameObjects/Space.h"
#include "Core/Game.h"
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
          drawEvent->Graphics.DrawString(Text, Font, Transform->Position, Color, Transform->Rotation, Transform->GetZLayer());
        }

        void DrawTextComponent::Initialize()
        {
          Transform = static_cast<TransformComponent*>(Owner.GetComponentByName("Transform"));

          Owner.AttachEventHandler(
            "Draw",
            [](void * obj, Event* event) { static_cast<DrawTextComponent *>(obj)->Draw(static_cast<DrawEvent *>(event)); },
            this);
        }

        void DrawTextComponent::DeSerialize(const IO::XML::XMLElement & element)
        {
          Component::DeSerialize(element);

          Text = element.GetAttributeValueByName("Text");
          Color = element.GetAttributeValueByName("Color", Graphics::Color(1, 1, 1, 1));
          Font = element.GetAttributeValueByName("Font", Game.Graphics->GetDefaultTextFormat());
        }

        //! this is unsafe
        void DrawTextComponent::Serialize(IO::XML::XMLElement & element) const
        {
          Component::Serialize(element);

          //todo make this safe
          element.SetAttribute("Text", Text);//! this is unsafe (Could invalidate XML) if "s are present
          element.SetAttribute("Color", Color);
          element.SetAttribute("Font", Font);
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
