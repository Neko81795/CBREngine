#include "GameObject.h"
#include "Components/DrawEvent.h"
#include "Components/TransformComponent.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      int GameObject::CompareTo(const GameObjectBase* other)const
      {
        if(other->Type != "GameObject")
          return -1;

        const GameObject &g = *dynamic_cast<const GameObject *>(other);
        
        const Components::TransformComponent * myTrans = dynamic_cast<const Components::TransformComponent *>(GetComponentByName("Transform"));
        const Components::TransformComponent * gTrans = dynamic_cast<const Components::TransformComponent *>(g.GetComponentByName("Transform"));

        if(!myTrans && !gTrans)
          return 0;
        else if(!myTrans)
          return 1;
        else if(!gTrans)
          return -1;

        if(myTrans->GetZLayer() < gTrans->GetZLayer())
          return -1;
        else if(myTrans->GetZLayer() > gTrans->GetZLayer())
          return 1;
        else
          return 0;
      }

      GameObject::GameObject(Core::Game &game, GameObjects::Space &space) : GameObjectBase(game,space)
      {
        Type = "GameObject";
      }

      GameObject::~GameObject()
      {
        
      }
    }
  }
}
