#include "DrawComponent.h"
#include "../GameObject.h"
#include "../Space.h"
#include <sstream>


namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        void DrawComponent::Draw(DrawEvent * drawEvent)
        {
          switch(Type)
          {
            case DrawComponent::Rectangle:
              if(Mode == DrawMode::Fill)
                drawEvent->Graphics.FillRectangle(Transform->Position, Transform->Scale, Color, Transform->Rotation, Transform->GetZLayer());
              else
                drawEvent->Graphics.DrawRectangle(Transform->Position, Transform->Scale, Color, Stroke, Transform->Rotation, Transform->GetZLayer());
              break;
            case DrawComponent::Ellipse:
              Vector2 center(Transform->Scale.Width * 16, Transform->Scale.Height * 16);
              if(Mode == DrawMode::Fill)
                drawEvent->Graphics.FillEllipse(Transform->Position, Transform->Scale, Color, Transform->Rotation, center, Transform->GetZLayer());
              else
                drawEvent->Graphics.DrawEllipse(Transform->Position, Transform->Scale, Color, Stroke, Transform->Rotation, center, Transform->GetZLayer());
              break;
          }
        }

        void DrawComponent::Initialize()
        {
          Transform = static_cast<TransformComponent*>(Owner.GetComponentByName("Transform"));

          //lambda
          Owner.AttachEventHandler(
            "Draw",
            [](void * obj, Event* event) { static_cast<DrawComponent *>(obj)->Draw(static_cast<DrawEvent *>(event)); },
            this);
        }

        void DrawComponent::DeSerialize(const IO::XML::XMLElement & element)
        {
          Component::DeSerialize(element);
          
          Mode = static_cast<DrawMode>(element.GetAttributeValueByName<int>("Mode"));
          Type = static_cast<GeometryType>(element.GetAttributeValueByName<int>("Type"));
          Stroke = element.GetAttributeValueByName("Stroke", 1.0f);
          Color = element.GetAttributeValueByName("Color", Graphics::Color(1,1,1,1));
        }

        void DrawComponent::Serialize(IO::XML::XMLElement & element) const
        {
          Component::Serialize(element);

          element.SetAttribute("Type", Type);
          element.SetAttribute("Mode", Mode);
          element.SetAttribute("Stroke", Stroke);
          element.SetAttribute("Color", Color);
        }

        DrawComponent::DrawComponent(GameObjects::GameObjectBase * owner) : Component(owner, "Transform"), Color(1.0f, 1.0f, 1.0f)
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
