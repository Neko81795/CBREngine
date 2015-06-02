#pragma once
#include "Delegate.h"
#include "Event.h"
#include <string>
#include <map>
#include <list>

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        class Component; // forward declaration
      }
    }
    class Eventful
    {
      ///////////////////////////////
      //Variables
      ///////////////////////////////
    protected:
      std::map<std::string, std::list<Delegate<Event *>>> EventListeners;

      ///////////////////////////////
      //Methods
      ///////////////////////////////
    public:
      /// <summary>
      /// Dispatches the event to all those listening
      /// </summary>
      /// <param name="eventID"> the ID of the event to dispatch </param>
      /// <param name="event"> a pointer to the data for this event </param>
      bool DispatchEvent(const std::string &eventID, Event *event);
      /// <summary>
      /// Informs the object that you would like to listen to the given event.
      /// When the event is dispatched the object will call the given delegate.
      /// </summary>
      /// <param name="eventID"> the ID of the event to listen to </param>
      /// <param name="func"> the function to call when the event happens </param>
      /// <param name="listener"> the object listening for this event </param>
      void AttachEventHandler(const std::string &eventID, void(*func)(void*, Event*), GameObjects::Components::Component *listener);
      /// <summary>
      /// Informs the object that you would like to stop listening to the given event.
      /// </summary>
      /// <param name="eventID"> the ID of the event to listen to </param>
      /// <param name="delegate"> the delegate to remove </param>
      /// <param name="listener"> the object that was listening for this event </param>
      void DetachEventHandler(const std::string &eventID, Delegate<Event *> delegate, GameObjects::Components::Component *listener);
      /// <summary>
      /// Informs the object that you would like to stop listening all events.
      /// </summary>
      /// <param name="listener"> the object that was listening for this event </param>
      void DetachAllEventHandlers(GameObjects::Components::Component *listener);
      virtual ~Eventful();
    };
  }
}

