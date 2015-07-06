#include "DrawTextComponent.h"
#include "../GameObject.h"
#include "../Space.h"

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
          drawEvent->Graphics.DrawString(Text, Transform->Position * 32, Color, Transform->Rotation, Transform->GetZLayer());
        }

        void DrawTextComponent::Initialize()
        {
          Transform = static_cast<TransformComponent*>(Owner.GetComponentByName("Transform"));

          Owner.AttachEventHandler(
            "Draw",
            [](void * obj, Event* event) { static_cast<DrawTextComponent *>(obj)->Draw(static_cast<DrawEvent *>(event)); },
            this);
        }

        DrawTextComponent::DrawTextComponent(GameObjects::GameObjectBase *owner) : Component(owner, "Transform")
        {
          Name = "DrawText";
        }


        DrawTextComponent::~DrawTextComponent()
        {}
      }
    }
  }
}
