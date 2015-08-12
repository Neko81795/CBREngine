#include "ConsoleComponent.h"
#include "../GameObjectBase.h"
#include "../Space.h"
#include "UpdateEvent.h"
#include "DrawTextComponent.h"
#include "../../../Input/Keyboard.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        
        void ConsoleComponent::Update(UpdateEvent * /*event*/)
        {
          if (Input::Keyboard::isKeyPressed(Input::Key::OEM_Grave))
          {
            if (ConsoleVisable)
            {
              ConsoleVisable = false;
              Game.UnRegisterDraw(ConsoleSpace);
            }
            else
            {
              ConsoleVisable = true;
              Game.RegisterDraw(ConsoleSpace);
            }
          }
        }

        ConsoleComponent::ConsoleComponent(GameObjects::GameObjectBase *owner) : Component(owner)
        {
          ConsoleSpace = &Owner.Game.CreateNamedSpace("Console");
          ConsoleSpace->SetSpaceLayer(1024);
          Game.UnRegisterDraw(ConsoleSpace);

          Console = &ConsoleSpace->CreateObjectAt(Vector2());

          Console->AddComponentByName<DrawTextComponent>("DrawText")->Text = "WAAAAAZUUUUP";

          Space.AttachEventHandler(
            "Update",
            [](void * obj, Event* event) { static_cast<ConsoleComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
            this);
        }


        ConsoleComponent::~ConsoleComponent()
        {
          ConsoleSpace = NULL;
          Owner.Game.RemoveSpaceByName("Console");
        }
      }
    }
  }
}
