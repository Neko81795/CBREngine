#include "DrawBitmapComponent.h"
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
        void DrawBitmapComponent::Draw(DrawEvent * drawEvent)
        {
          if (Image != NULL)
          {
            Size2 size = Image->GetSize();
            drawEvent->Graphics.DrawBitmap(*Image, Transform->Position * 32, 1, Vector2(static_cast<float>(size.Width)/2, static_cast<float>(size.Height) / 2), Transform->Rotation, Transform->Scale);
          }
        }

        void DrawBitmapComponent::Initialize()
        {
          Transform = static_cast<TransformComponent*>(Owner.GetComponentByName("Transform"));

          //lambda
          Space.AttachEventHandler(
            "Draw",
            [](void * obj, Event* event) { static_cast<DrawBitmapComponent *>(obj)->Draw(static_cast<DrawEvent *>(event)); },
            this);
        }

        DrawBitmapComponent::DrawBitmapComponent(GameObjects::GameObject *owner) : Component(owner, "Transform")
        {
          Name = "DrawBitmap";
          Image = NULL;
        }
      }
    }
  }
}
