#include "GameObject.h"

namespace CBREngine
{
  namespace Core
  {
    namespace GameObjects
    {
      long long GameObject::Count = 0;

      void GameObject::RemoveComponentByName(const std::string& name)
      {
        for (auto it = _components.begin(); it != _components.end(); ++it)
        {
          if ((*it)->Name == name)
          {
            Components::Component *comp = *it;
            _components.erase(it);
            delete comp;
            break;
          }
        }
      }

      const std::list<Components::Component*>& GameObject::GetComponents()
      {
        return _components;
      }
      
      Components::Component* GameObject::GetComponentByName(std::string name)
      {
        for (Components::Component* current : _components)
        {
          if (current->Name == name)
            return current;
        }
        return NULL;
      }

      GameObject::GameObject(Core::Game &game, GameObjects::Space &space) : Game(game), Space(space)
      {
        ID = GameObject::Count++;
        Name = std::to_string(ID);
      }

      GameObject::~GameObject()
      {
        for (auto it = _components.begin(); it != _components.end(); it = _components.begin())
        {
          Components::Component *comp = *it;
          _components.pop_front();
          delete comp;
        }
      }
    }
  }
}
