#include "Space.h"
#include "Components/UpdateEvent.h"
#include "Components/TransformComponent.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      void Space::Update()
      {
        GameTime.Tick();
        Components::UpdateEvent ue(GameTime);
        DispatchEvent("Update", &ue);
      }

      GameObject& Space::CreateObject()
      {
        GameObject *obj = new MistThread::Core::GameObjects::GameObject(Game, *this);
        Objects.push_back(obj);
        RegisterDraw(obj);
        return *obj;
      }

      GameObject& Space::CreateObjectAt(const Vector2 &pos, float zLayer)
      {
        GameObject &obj = *new MistThread::Core::GameObjects::GameObject(Game, *this);
        Objects.push_back(&obj);
        auto& trans = *dynamic_cast<Components::TransformComponent*>(obj.AddComponentByName("Transform"));
        trans.Position = pos;
        trans.SetZLayer(zLayer);
        RegisterDraw(&obj);
        return obj;
      }

      GameObject& Space::FindObjectByName(const std::string &name)
      {
        for(auto obj : Objects)
        {
          if(obj->Name == name)
            return *dynamic_cast<GameObject*>(obj);
        }
        //TODO add what the name of the object was.
        throw std::exception("Could not find object");
      }

      const std::list<GameObject *> Space::FindObjectsByName(const std::string &name)
      {
        std::list<GameObject *> objects;
        for(auto obj : Objects)
        {
          if(obj->Name == name)
            objects.push_back(static_cast<GameObject*>(obj));
        }
        return objects;
      }

      void Space::RemoveObjectByName(const std::string &name)
      {
        RemoveGameObjectBaseByName(name);
      }

      int Space::CompareTo(const GameObjectBase* other)const
      {
        if(other->Type == "Game")
          return -1;
        if(other->Type == "GameObject")
          return 1;

        const Space &s = *dynamic_cast<const Space*>(other);

        return this->SpaceLayer - s.SpaceLayer;
      }

      Space::Space(Core::Game & game) : GameObjectBase(game, *this)
      {
        Type = "Space";
      }

      Space::~Space()
      {

      }
    }
  }
}
