#include "DrawBitmapComponent.h"
#include "Core/GameObjects/GameObject.h"
#include "Core/GameObjects/Space.h"
#include "Utilities/ContentManager.h"
#include "Core/Exception.h"
#include <sstream>



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
            drawEvent->Graphics.DrawBitmap(*Image, Transform->Position, Opacity, Vector2(static_cast<float>(size.Width)/2, static_cast<float>(size.Height) / 2), Transform->Rotation, Transform->Scale, NULL, Transform->GetZLayer());
          }
        }

        void DrawBitmapComponent::Initialize()
        {
          Transform = static_cast<TransformComponent*>(Owner.GetComponentByName("Transform"));
          
          Owner.AttachEventHandler(
            "Draw",
            [](void * obj, Event* event) { static_cast<DrawBitmapComponent *>(obj)->Draw(static_cast<DrawEvent *>(event)); },
            this);
        }

        void DrawBitmapComponent::LoadImageFromFile(const std::string & path)
        {
          ImagePath = path;
          Image = &Utilities::ContentManager::LoadBitmapFile(path);
        }

        void DrawBitmapComponent::DeSerialize(const IO::XML::XMLElement & element)
        {
          Component::DeSerialize(element);

          ImagePath = element.GetAttributeByName("Path")->Value;
          Image = &Utilities::ContentManager::LoadBitmapFile(ImagePath);

          Opacity = element.GetAttributeValueByName("Opacity", 1.0f);
        }

        void DrawBitmapComponent::Serialize(IO::XML::XMLElement & element) const
        {
          Component::Serialize(element);
          element.SetAttribute("Path", ImagePath);
          element.SetAttribute("Opacity", Opacity);
        }

        DrawBitmapComponent::DrawBitmapComponent(GameObjects::GameObjectBase *owner) : Component(owner, "Transform")
        {
          Name = "DrawBitmap";
          Image = NULL;
        }
      }
    }
  }
}
