#include "Space.h"
#include "Components/UpdateEvent.h"
#include "Components/DrawEvent.h"

namespace CBREngine
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

      void Space::Draw(Graphics::Engines::GraphicsEngineCore & graphics)
      {
        Components::DrawEvent de(graphics);
        DispatchEvent("Draw", &de);
      }

      void Space::Initialize()
      {
        for (GameObject & go : Objects)
        {
          for (Components::Component *com : go._components)
            com->Initialize();
        }
      }

      GameObject& Space::CreateObject()
      {
        Objects.push_back(CBREngine::Core::GameObjects::GameObject(Game, *this));
        return Objects.back();
      }

      GameObject& Space::CreateObjectAt(Vector2 /*pos*/)
      {
        Objects.push_back(CBREngine::Core::GameObjects::GameObject(Game, *this));
        GameObject &obj = Objects.back();
        //TODO add component of transform here.

        return obj;
      }

      Space::Space(Core::Game & game, Graphics::Engines::LimitedGraphicsEngineCore *graphics) : Game(game)
      {
        pGraphics = graphics;
      }

      Space::~Space()
      {

      }
    }
  }
}
