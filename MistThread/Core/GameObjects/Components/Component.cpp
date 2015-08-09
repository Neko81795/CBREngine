#include "Component.h"
#include "../../Event.h"
#include "../GameObject.h"
#include "../GameObjectBase.h"
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

        void Component::InitializeFromXML(const IO::XML::XMLElement & element)
        {
          //this doesn't actually have to be done, but I'm doing it anyway for an example
          Name = element.GetAttributeByName("Name").Value;
        }

        void Component::PopulateXML(IO::XML::XMLElement & element) const
        {
          //set the name
          element.SetAttribute("Name", Name);
        }

        Component::Component(GameObjects::GameObjectBase * owner) : Owner(*owner), Space(owner->Space), Game(owner->Game)
        {
          
        }

        Component::Component(GameObjects::GameObjectBase * owner, const std::vector<std::string>& dependencies) : Owner(*owner), Space(owner->Space), Game(owner->Game)
        {
          Dependencies = std::vector<std::string>(dependencies);
        }

        Component::Component(GameObjects::GameObjectBase * owner, const std::string & dependencies) : Owner(*owner), Space(owner->Space), Game(owner->Game)
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
