#include "Space.h"
#include "Components/UpdateEvent.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      void Space::Update(const GameTime & gameTime)
      {
        Components::UpdateEvent ue(gameTime);
        DispatchEvent("Update", &ue);
      }

      GameObject& Space::CreateObject()
      {
        Objects.push_back(MistThread::Core::GameObjects::GameObject(Game, *this));
        return Objects.back();
      }

      GameObject& Space::CreateObjectAt(Vector2 /*pos*/)
      {
        Objects.push_back(MistThread::Core::GameObjects::GameObject(Game, *this));
        GameObject &obj = Objects.back();
        //TODO add component of transform here.

        return obj;
      }

      Space::Space(Core::Game & game, Graphics::Engines::LimitedGraphicsEngineCore *graphics) : GameObjectBase(game, *this)
      {
        pGraphics = graphics;
      }

      Space::~Space()
      {

      }
    }
  }
}
