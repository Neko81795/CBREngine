#include "GameObject.h"
#include "Components/DrawEvent.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      long long GameObject::Count = 0;


      void GameObject::Draw(Graphics::Engines::GraphicsEngineCore & graphics)
      {
        Components::DrawEvent de(graphics);
        DispatchEvent("Draw", &de);
      }

      GameObject::GameObject(Core::Game &game, GameObjects::Space &space) : GameObjectBase(game,space)
      {
      }

      GameObject::~GameObject()
      {
        
      }
    }
  }
}
