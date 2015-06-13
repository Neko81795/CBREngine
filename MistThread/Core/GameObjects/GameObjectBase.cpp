#include "GameObjectBase.h"
#include "Components/Component.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      void GameObjectBase::SwapDraw(int index1, int index2)
      {
        GameObjectBase *temp = Objects[index1];
        Objects[index1] = Objects[index2];
        Objects[index2] = temp;
      }

      const std::map<std::string, Components::Component*>& GameObjectBase::GetComponents()
      {
        return Components;
      }

      Components::Component* GameObjectBase::GetComponentByName(std::string name)
      {
        return Components[name];
      }

      void GameObjectBase::RemoveComponentByName(const std::string& name)
      {
        if(Components[name])
        {
          delete Components[name];
          Components.erase(name);
        }
      }

      bool GameObjectBase::DispatchEvent(const std::string & eventID, Event * event)
      {
        std::list<Delegate<Event *>> el = EventListeners[eventID];

        for(auto d : el)
          d(event);
        return true;
      }

      void GameObjectBase::AttachEventHandler(const std::string & eventID, void(*func)(void*, Event*), GameObjects::Components::Component *listener)
      {

        EventListeners[eventID].push_back(Delegate<Event*>(func, listener));
        listener->EventDispatchers[this].push_back(Delegate<Event*>(func, listener));
        listener->DelegateIDs[Delegate<Event*>(func, listener)] = eventID;
      }

      void GameObjectBase::DetachEventHandler(const std::string & eventID, Delegate<Event*> delegate, GameObjects::Components::Component *listener)
      {
        EventListeners[eventID].remove(delegate);
        listener->EventDispatchers[this].remove(delegate);
        listener->DelegateIDs.erase(delegate);
      }

      void GameObjectBase::DetachAllEventHandlers(GameObjects::Components::Component *listener)
      {
        for(auto d : listener->EventDispatchers)
        {
          if(d.first == this)
          {
            for(auto e : d.second)
            {
              this->DetachEventHandler(listener->DelegateIDs.find(e)->second, e, listener);
            }
          }
        }
      }

      void GameObjectBase::Initialize()
      {
        for(auto pair : Components)
        {
          pair.second->Initialize();
        }

        for(GameObjectBase * go : Objects)
        {
            go->Initialize();
        }
      }

      void GameObjectBase::Draw(Graphics::Engines::GraphicsEngineCore &/*graphics*/)
      {

      }

      GameObjectBase::GameObjectBase(Core::Game &game, GameObjects::Space &space) : Game(game), Space(space)
      {
        ID = GameObjectBase::Count++;
        Name = std::to_string(ID);
      }

      GameObjectBase::~GameObjectBase()
      {
        for(auto pair : Components)
        {
          delete pair.second;
          pair.second = NULL;
        }
        for(size_t i = Objects.size() - 1; i < Objects.size(); i--)
        {
          delete Objects[i];
          Objects.pop_back();
        }
      }
    }
  }
}
