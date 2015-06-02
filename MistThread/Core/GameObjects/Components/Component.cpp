#include "Component.h"
#include "../../Event.h"
#include "../../Eventful.h"
#include "../GameObject.h"
#include "../Space.h"
#include "../../Game.h"

#include <sstream>

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        void Component::Initialize()
        {

        }

        Component::Component(GameObjects::GameObject * owner) : Owner(*owner), Space(owner->Space), Game(owner->Game)
        {
          
        }

        Component::Component(GameObjects::GameObject * owner, const std::vector<std::string>& dependencies) : Owner(*owner), Space(owner->Space), Game(owner->Game)
        {
          Dependencies = std::vector<std::string>(dependencies);
        }

        Component::Component(GameObjects::GameObject * owner, const std::string & dependencies) : Owner(*owner), Space(owner->Space), Game(owner->Game)
        {
          std::stringstream stream;
          stream << dependencies;
          
          while (!stream.eof())
          {
            std::string str;
            stream >> str;

            if(str != "")
              Dependencies.push_back(str);
          }
        }

        Component::~Component()
        {
          for (auto ed : EventDispatchers)
          {
            ed.first->DetachAllEventHandlers(this);
          }
        }
      }
    }
  }
}
