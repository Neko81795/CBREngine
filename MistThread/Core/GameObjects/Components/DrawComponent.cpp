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
                drawEvent->Graphics.FillRectangle(Transform->Position * 32, Transform->Scale * 32, Color, Transform->Rotation, Transform->GetZLayer());
              else
                drawEvent->Graphics.DrawRectangle(Transform->Position * 32, Transform->Scale * 32, Color, Stroke, Transform->Rotation, Transform->GetZLayer());
              break;
            case DrawComponent::Ellipse:
              Vector2 center(Transform->Scale.Width * 16, Transform->Scale.Height * 16);
              if(Mode == DrawMode::Fill)
                drawEvent->Graphics.FillEllipse(Transform->Position * 32, Transform->Scale * 32, Color, Transform->Rotation, center, Transform->GetZLayer());
              else
                drawEvent->Graphics.DrawEllipse(Transform->Position * 32, Transform->Scale * 32, Color, Stroke, Transform->Rotation, center, Transform->GetZLayer());
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

        void DrawComponent::InitializeFromXML(const IO::XML::XMLElement & element)
        {
          Component::InitializeFromXML(element);
          
          std::stringstream str(element.GetAttributeByName("Mode").Value);
          int temp;
          str >> temp;
          Mode = static_cast<DrawMode>(temp);

          str = std::stringstream(element.GetAttributeByName("Type").Value);
          str >> temp;
          Type = static_cast<GeometryType>(temp);

          str = std::stringstream(element.GetAttributeByName("Stroke").Value);
          str >> Stroke;

          str = std::stringstream(element.GetAttributeByName("Color").Value);
          str >> Color;
        }

        void DrawComponent::PopulateXML(IO::XML::XMLElement & element) const
        {
          Component::PopulateXML(element);
          std::stringstream str;
          str << Type;
          element.SetAttribute("Type", str.str());

          str = std::stringstream();
          str << Mode;
          element.SetAttribute("Mode", str.str());

          str = std::stringstream();
          str << Stroke;
          element.SetAttribute("Stroke", str.str());

          str = std::stringstream();
          str << Color;
          element.SetAttribute("Color", str.str());
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
