#pragma once
#include <map>
#include <list>
#include <vector>

#include "../Delegate.h"
#include "../Event.h"
#include "Components/TransformComponent.h"

#define __ABSTRACT = 0

namespace MistThread
{
  namespace Graphics
  {
    namespace Engines
    {
      class GraphicsEngineCore; // forward declaration
    }
  }
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        class Component; // forward declaration
      }
      class Space; // forward declaration




      class GameObjectBase
      {
        friend class Game;
        friend class GameObject;
        friend class Space;
        friend class Components::TransformComponent;
//////////////////////////////////////////////////////////////
//Variables
//////////////////////////////////////////////////////////////
      protected:
        /// <summary>
        /// a map of the lists of delegates that should be called when an event is dispatched
        /// </summary>
        std::map<std::string, std::list<Delegate<Event *>>> EventListeners;
        /// <summary>
        /// the components this object should hold and run
        /// </summary>
        std::map<std::string, Components::Component*> Components;
        /// <summary>
        /// the objects in this object. the pointers will be handled by this list
        /// </summary>
        std::vector<GameObjectBase*> Objects;
        /// <summary>
        /// the objects to be drawn by this one. the pointers will not be handled by this list
        /// </summary>
        std::vector<GameObjectBase*> DrawOrder;
        /// <summary>
        /// the index in this objects draw list that it is
        /// </summary>
        size_t OwnIndex;
        /// <summary>
        /// the index in the drawlist that it is currently in
        /// </summary>
        size_t DrawIndex;
        /// <summary>
        /// what object draws this one
        /// </summary>
        GameObjectBase *DrawnBy;
        /// <summary>
        /// used to identify what this actually is
        /// </summary>
        std::string Type;
      public:
        static long long Count;

        Core::Game &Game;
        GameObjects::Space &Space;
        std::string Name;
        long long ID;

//////////////////////////////////////////////////////////////
//Methods
//////////////////////////////////////////////////////////////
      private:
        GameObjectBase& operator=(const GameObjectBase&) {}
      protected:
        /// <summary>
        /// swaps the position of two objects in the draw list
        /// </summary>
        /// <param name="index1">the index of the first</param>
        /// <param name="index2">the index of the second</param>
        void SwapDraw(size_t index1, size_t index2);
        /// <summary>
        /// swaps the position of this object with another in this objects draw list
        /// </summary>
        /// <param name="index">the index of the other object</param>
        void SwapSelfWith(size_t index);
        /// <summary>
        /// removes the object with the name given
        /// </summary>
        /// <param name="name">the name of the object to remove</param>
        void RemoveGameObjectBaseByName(const std::string &name);
      public:
        template <typename CType>
        CType& AddComponent();
        /// <summary>
        /// returns all of the components
        /// </summary>
        /// <returns></returns>
        const std::map<std::string, Components::Component *>& GetComponents();
        /// <summary>
        /// returns a pointer to the component who's name matches the one provided
        /// </summary>
        /// <param name="name">the name of the component to find</param>
        Components::Component* GetComponentByName(const std::string &name);
        /// <summary>
        /// returns a pointer to the component who's name matches the one provided
        /// </summary>
        /// <param name="name">the name of the component to find</param>
        const Components::Component* GetComponentByName(const std::string &name) const;
        /// <summary>
        /// Removes the component with the given name
        /// </summary>
        /// <param name="name">The name of the component to remove</param>
        void RemoveComponentByName(const std::string& name);
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
        /// <summary>
        /// runs initialization on all components
        /// </summary>
        void Initialize();
        /// <summary>
        /// Drawing logic for throwing the events in a specific order
        /// </summary>
        /// <param name="graphics">the graphics engine to use</param>
        /// <param name="caller">the one calling, used in logic</param>
        void Draw(Graphics::Engines::GraphicsEngineCore &graphics, GameObjectBase* caller = NULL);
        /// <summary>
        /// adds the given object to this objects draw list
        /// </summary>
        /// <param name="object">the object to add</param>
        void RegisterDraw(GameObjectBase * object);
        /// <summary>
        /// removes the given object from this objects draw list
        /// </summary>
        /// <param name="object">the object to remove</param>
        void UnRegisterDraw(GameObjectBase * object);
        /// <summary>
        /// updates the position on the draw list of the given object
        /// </summary>
        /// <param name="object">the object to update the draw list position of</param>
        void UpdateObjectDrawOrder(GameObjectBase* object);
        /// <summary>
        /// updates the position of this object in its own draw list
        /// </summary>
        void UpdateOwnDrawOrder();
        /// <summary>
        /// compares this object to another for sorting
        /// value will be less than, greater than, or equal to 0.
        /// </summary>
        virtual int CompareTo(const GameObjectBase* other)const __ABSTRACT;
//////////////////////////////////////////////////////////////
//Constructors
//////////////////////////////////////////////////////////////
      public:
        GameObjectBase(Core::Game &game, GameObjects::Space &space);
        virtual ~GameObjectBase();
      };






//////////////////////////////////////////////////////////////
//Template Definitions
//////////////////////////////////////////////////////////////

      /// <summary>
      /// Adds the component of the given type
      /// </summary>
      /// <typeParam name="CType"> The type of the component to add </typeParam>
      /// <example> obj.AddComponent[DrawComponent]() </example>
      /// <exception cref="std::exception"> thrown if needed dependencies don't exist </exception>
      /// <exception cref="std::exception"> thrown when component is already present on the object </exception>
      template <typename CType>
      CType& GameObjectBase::AddComponent()
      {
        CType *ctypeptr = new CType(this);
        Components::Component *ptr = ctypeptr;
        //if its already there, delete the one you just made and return the original
        if(Components[ptr->Name])
        {
          delete ctypeptr;
          throw new std::exception("Component already exists on this Object");
        }

        //check that the dependencies are there
        for(const std::string &dep : ptr->Dependencies)
        {
          if(!Components[dep])
          {
            delete ctypeptr;
            throw new std::exception("Component dependency could not be found"); //TODO add what component was not found
          }
        }

        Components[ptr->Name] = ptr;
        return *ctypeptr;
      }
    }
  }
}
