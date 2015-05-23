#include "DrawComponent.h"
#include "../GameObject.h"
#include "../Space.h"


namespace CBREngine
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        void DrawComponent::Draw(DrawEvent * drawEvent)
        {
          switch (Type)
          {
            case DrawComponent::Rectangle:
              if (Mode == DrawMode::Fill)
                drawEvent->Graphics.FillRectangle(Transform->Position * 32, Transform->Scale  * 32, Color, Transform->Rotation);
              else
                drawEvent->Graphics.DrawRectangle(Transform->Position * 32, Transform->Scale  * 32, Color, Stroke, Transform->Rotation);
              break;
            case DrawComponent::Elipse:
              Vector2 center(Transform->Scale.Width * 16, Transform->Scale.Height * 16);
              if (Mode == DrawMode::Fill)
                drawEvent->Graphics.FillEllipse(Transform->Position  * 32, Transform->Scale  * 32, Color, Transform->Rotation, center);
              else
                drawEvent->Graphics.DrawEllipse(Transform->Position  * 32, Transform->Scale  * 32, Color, Stroke, Transform->Rotation, center);
              break;
          }
        }

        void DrawComponent::Initialize()
        {
          Transform = static_cast<TransformComponent*>(Owner.GetComponentByName("Transform"));

          //lambda
          Space.AttachEventHandler(
            "Draw", 
            [](void * obj, Event* event){ static_cast<DrawComponent *>(obj)->Draw(static_cast<DrawEvent *>(event)); }, 
            this);
        }

        DrawComponent::DrawComponent(GameObjects::GameObject * owner) : Component(owner, "Transform"), Color(1.0f, 1.0f, 1.0f)
        {
          Stroke = 1;
          Name = "Draw";
        }

        DrawComponent::~DrawComponent()
        {

        }
      }
    }
  }
}
