#include "Eventful.h"
#include "GameObjects/Components/Component.h"


namespace CBREngine
{
  namespace Core
  {
    bool Eventful::DispatchEvent(const std::string & eventID, Event * event)
    {
      std::list<Delegate<Event *>> el = EventListeners[eventID];

      for (auto d : el)
        d(event);
      return true;
    }

    void Eventful::AttachEventHandler(const std::string & eventID, Delegate<Event*> delegate, GameObjects::Components::Component *listener)
    {
      EventListeners[eventID].push_back(delegate);
      listener->EventDispatchers[this].push_back(delegate);
      listener->DelegateIDs[delegate] = eventID;
    }

    void Eventful::DetachEventHandler(const std::string & eventID, Delegate<Event*> delegate, GameObjects::Components::Component *listener)
    {
      EventListeners[eventID].remove(delegate);
      listener->EventDispatchers[this].remove(delegate);
      listener->DelegateIDs.erase(delegate);
    }

    void Eventful::DetachAllEventHandlers(GameObjects::Components::Component *listener)
    {
      for (auto d : listener->EventDispatchers)
      {
        if (d.first == this)
        {
          for (auto e : d.second)
          {
            this->DetachEventHandler(listener->DelegateIDs.find(e)->second, e, listener);
          }
        }
      }
    }

    Eventful::~Eventful()
    {

    }
  }
}
