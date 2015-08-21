#include "GameObjectBase.h"
#include "Components/Component.h"
#include "Components/TransformComponent.h"
#include "../Exception.h"
#include "../Game.h"
#include "Space.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      long long GameObjectBase::Count = 0;


      void GameObjectBase::SwapDraw(size_t index1, size_t index2)
      {
        if(DrawOrder[index1] == this)
          return SwapSelfWith(index2);
        else if(DrawOrder[index2] == this)
          return SwapSelfWith(index1);

        GameObjectBase *temp = DrawOrder[index1];
        DrawOrder[index1] = DrawOrder[index2];
        DrawOrder[index2] = temp;

        DrawOrder[index1]->DrawIndex = index1;
        DrawOrder[index2]->DrawIndex = index2;
      }

      void GameObjectBase::SwapSelfWith(size_t index)
      {
        size_t index2 = OwnIndex;
        GameObjectBase *temp = DrawOrder[index2];
        DrawOrder[index2] = DrawOrder[index];
        DrawOrder[index] = temp;

        DrawOrder[index2]->DrawIndex = index2;
        DrawOrder[index]->OwnIndex = index;
      }

      void GameObjectBase::RemoveGameObjectBaseByName(const std::string &name)
      {
        for(int i = 0; i < Objects.size(); i++)
        {
          if(Objects[i]->Name == name)
          {
            if(Objects[i]->DrawnBy)
              Objects[i]->DrawnBy->UnRegisterDraw(Objects[i]);

            delete Objects[i];
            Objects[i] = Objects[Objects.size() - 1];
            Objects.pop_back();
            return;
          }
        }
      }

      void GameObjectBase::RemoveGameObjectBaseByID(long long id)
      {
        for(int i = 0; i < Objects.size(); i++)
        {
          if(Objects[i]->ID == id)
          {
            if(Objects[i]->DrawnBy)
              Objects[i]->DrawnBy->UnRegisterDraw(Objects[i]);

            delete Objects[i];
            Objects[i] = Objects[Objects.size() - 1];
            Objects.pop_back();
            return;
          }
        }
      }

      Components::Component* GameObjectBase::AddComponentByName(const std::string &name)
      {
        GameObjects::Components::Component* (*construct)(GameObjectBase*) = Game::ComponetConstructors[name];

        //if we don't know about this component, complain
        if(!construct)
          throw Exception(("Component '" + name + "' does not exist").c_str());

        Components::Component *ptr = construct(this);

        //if its already there, delete the one you just made and return the original
        if(Components[ptr->Name])
        {
          delete ptr;
          throw Exception(("Component '" + name + "' already exists on this object").c_str());
        }

        //check that the dependencies are there
        for(const std::string &dep : ptr->Dependencies)
        {
          if(!Components[dep])
          {
            delete ptr;
            throw Exception(("Component dependency could not be found: " + dep).c_str());
          }
        }

        Components[ptr->Name] = ptr;
        return ptr;
      }

      const std::map<std::string, Components::Component*>& GameObjectBase::GetComponents()
      {
        return Components;
      }

      Components::Component* GameObjectBase::GetComponentByName(const std::string &name)
      {
        return Components[name];
      }

      const Components::Component* GameObjectBase::GetComponentByName(const std::string &name) const
      {
        //! holy crap I can't believe I just did that! *panicked hoers noises*
        return (*const_cast<std::map<std::string, Components::Component*>*>(&Components))[name];
      }

      //todo: don't allow people to remove things that are depended on
      void GameObjectBase::RemoveComponentByName(const std::string& name)
      {
        if(Components[name])
        {
          Components::Component* comp = Components[name];
          Components.erase(name);
          delete comp;
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
        ComponentsListening.remove(listener);
        ComponentsListening.push_back(listener);
      }

      void GameObjectBase::DetachEventHandler(const std::string & eventID, Delegate<Event*> delegate, GameObjects::Components::Component *listener)
      {
        for(auto it = EventListeners[eventID].begin(); it != EventListeners[eventID].end(); it++)
        {
          if(*it == delegate)
          {
            EventListeners[eventID].erase(it);
            listener->EventDispatchers[this].remove(delegate);
            listener->DelegateIDs.erase(delegate);

            if(listener->EventDispatchers[this].size() == 0)
            {
              ComponentsListening.remove(listener);
            }

            break;
          }
        }
      }

      void GameObjectBase::DetachAllEventHandlers(GameObjects::Components::Component *listener)
      {
        while(listener->EventDispatchers[this].size())
        {
          auto e = listener->EventDispatchers[this].front();
          if(listener->DelegateIDs.size())
          {
            std::string eventID(listener->DelegateIDs[e]);
            if(eventID.length())
              this->DetachEventHandler(listener->DelegateIDs.find(e)->second, e, listener);
            else
              listener->DelegateIDs.erase(e);
          }

        }
      }

      void GameObjectBase::Initialize()
      {
        for(auto pair : Components)
        {
          if(pair.second)
            pair.second->Initialize();
        }

        for(GameObjectBase * go : Objects)
        {
          go->Initialize();
        }
      }

      void GameObjectBase::Draw(Graphics::Engines::GraphicsEngineCore &graphics, GameObjectBase *caller)
      {
        if(caller == this)
        {
          Graphics::GraphicsEvent evnt(&graphics);
          DispatchEvent("Draw", &evnt);
        }
        else
        {
          for(int i = 0; i < DrawOrder.size(); i++)
          {
            DrawOrder[i]->Draw(graphics, this);
          }
        }
      }

      void GameObjectBase::RegisterDraw(GameObjectBase *object)
      {
        object->DrawnBy = this;
        object->DrawIndex = DrawOrder.size();
        DrawOrder.push_back(object);
        UpdateObjectDrawOrder(object);
      }

      void GameObjectBase::UnRegisterDraw(GameObjectBase * object)
      {
        if(object->DrawnBy && object->DrawnBy == this)
        {
          while(object->DrawIndex != DrawOrder.size() - 1)
          {
            SwapDraw(object->DrawIndex, object->DrawIndex + 1);
          }
          object->DrawnBy = NULL;
          object->DrawIndex = 0;
          DrawOrder.pop_back();
        }
      }

      void GameObjectBase::UpdateObjectDrawOrder(GameObjectBase* object)
      {
        if(object->DrawIndex)
        {
          while(object->CompareTo(DrawOrder[object->DrawIndex - 1]) < 0)
          {
            SwapDraw(object->DrawIndex, object->DrawIndex - 1);

            if(!object->DrawIndex)
              return;
          }
        }
        if(object->DrawIndex < DrawOrder.size() - 1)
        {
          while(object->CompareTo(DrawOrder[object->DrawIndex + 1]) > 0)
          {
            SwapDraw(object->DrawIndex, object->DrawIndex + 1);

            if(object->DrawIndex == DrawOrder.size() - 1)
              return;
          }
        }
      }

      void GameObjectBase::UpdateOwnDrawOrder()
      {
        if(OwnIndex)
        {
          while(CompareTo(DrawOrder[OwnIndex - 1]) < 0)
          {
            SwapDraw(OwnIndex, OwnIndex - 1);

            if(!OwnIndex)
              return;
          }
        }
        if(OwnIndex < DrawOrder.size() - 1)
        {
          while(CompareTo(DrawOrder[OwnIndex + 1]) > 0)
          {
            SwapDraw(OwnIndex, OwnIndex + 1);

            if(OwnIndex == DrawOrder.size() - 1)
              return;
          }
        }
      }

      GameObjectBase::GameObjectBase(Core::Game &game, GameObjects::Space &space) : Game(game), Space(space)
      {
        ID = GameObjectBase::Count++;
        Name = std::to_string(ID);
        RegisterDraw(this);
        DrawnBy = NULL;
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
        while(ComponentsListening.size())
        {
          ComponentsListening.front()->EventDispatchers.erase(this);
          ComponentsListening.pop_front();
        }
      }
    }
  }
}
