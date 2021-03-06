#include "CameraComponent.h"
#include "../GameObject.h"
#include "../../Game.h"
#include "../../../Graphics/Engines/GraphicsEngineCore.h"

#include <sstream>

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        void CameraComponent::WindowResized(WindowEvent *)
        {
          auto &graphics = *Game::CurrentGame->Graphics;

          Size2 windowSize = graphics.GetWindowBounds();

          CameraScale = (windowSize.Height / 32.0f) / Size;
        }

        void CameraComponent::DeSerialize(const IO::XML::XMLElement & element)
        {
          Component::DeSerialize(element);

          Size = element.GetAttributeValueByName("Size", 20.0f);
        }

        void CameraComponent::Serialize(IO::XML::XMLElement & element) const
        {
          Component::Serialize(element);

          element.SetAttribute("Size", Size);
        }

        void CameraComponent::Initialize()
        {
          Space.Camera = &Owner;
          Transform = static_cast<TransformComponent*>(Owner.GetComponentByName("Transform"));

          Owner.Game.AttachEventHandler(
            "WindowResized",
            [](void * obj, Event* event) { static_cast<CameraComponent *>(obj)->WindowResized(static_cast<WindowEvent *>(event)); },
            this);

          auto &graphics = *Game::CurrentGame->Graphics;

          Size2 windowSize = graphics.GetWindowBounds();

          CameraScale = (windowSize.Height/32.0f) / Size;
        }

        CameraComponent::CameraComponent(GameObjects::GameObjectBase * owner) : Component(owner, "Transform")
        {
          Name = "Camera";
        }


        CameraComponent::~CameraComponent()
        {}
      }
    }
  }
}
