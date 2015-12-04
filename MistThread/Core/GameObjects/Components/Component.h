#pragma once
#include <map>
#include <list>
#include <vector>
#include <string>
#include "../../Delegate.h"
#include "../../../IO/XML/XMLElement.h"

namespace MistThread
{
  namespace Core
  {
    class Eventful; // forward declaration
    class Event; //forward declaration
    class Game; //forward declaration

    namespace GameObjects
    {
      class Space; //forward declaration
      class GameObject; //forward declaration
      class GameObjectBase; //forward declaration

      namespace Components
      {
        class Component
        {
          friend class GameObjectBase;
          ///////////////////////////////
          //Variables
          ///////////////////////////////
        private:
          std::map<GameObjectBase *, std::list<Delegate<Event *>>> EventDispatchers;
          std::map<Delegate<Event *>, std::string> DelegateIDs;
          Component& operator=(const Component&) = delete;
        public:
          std::string Name;
          GameObjects::Space &Space;
          Core::Game &Game;
          GameObjects::GameObjectBase &Owner;
          std::vector<std::string> Dependencies;


          ///////////////////////////////
          //Methods
          ///////////////////////////////
        public:
          /// <summary>
          /// Initializes the component
          /// Called when the level is loaded
          /// </summary>
          virtual void Initialize();
          /// <summary>
          /// Sets up the component from with the given XML Element
          /// </summary>
          /// <param name="element">the element with the data needed to initialize</param>
          virtual void InitializeFromXML(const IO::XML::XMLElement & element);
          /// <summary>
          /// Populates the given XML Element with data for saving
          /// </summary>
          /// <param name="element">the element to fill with data</param>
          virtual void PopulateXML(IO::XML::XMLElement & element) const;

          /// <summary>
          /// called when the owner is destroyed
          /// </summary>
          virtual void Destroyed();

          ///////////////////////////////
          //Constructors
          ///////////////////////////////
          /// <summary>
          /// Creates a new component
          /// </summary>
          /// <param name="owner">the owner of the component</param>
          Component(GameObjects::GameObjectBase * owner);
          /// <summary>
          /// Creates a new component
          /// </summary>
          /// <param name="owner">The owner of the component</param>
          /// <param name="dependencies">a list of dependencies</param>
          Component(GameObjects::GameObjectBase * owner, const std::vector<std::string>& dependencies);
          /// <summary>
          /// Creates a new component
          /// </summary>
          /// <param name="owner">the owner of the new component</param>
          /// <param name="dependencies">a space delimited list of names of components that must be present</param>
          Component(GameObjects::GameObjectBase * owner, const std::string& dependencies);
          virtual ~Component();
        };
      }
    }
  }
}
