#pragma once
#include <map>
#include <list>
#include <vector>
#include <string>
#include "../../Delegate.h"

namespace CBREngine
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

      namespace Components
      {
        class Component
        {
          friend class Eventful;
          ///////////////////////////////
          //Variables
          ///////////////////////////////
        private:
          std::map<Eventful *, std::list<Delegate<Event *>>> EventDispatchers;
          std::map<Delegate<Event *>, std::string> DelegateIDs;
          Component& operator=(const Component&) {}
        public:
          std::string Name;
          GameObjects::Space &Space;
          Core::Game &Game;
          GameObjects::GameObject &Owner;
          std::vector<std::string> Dependencies;


          ///////////////////////////////
          //Methods
          ///////////////////////////////
          /// <summary>
          /// Initializes the component
          /// Called when the level is loaded
          /// </summary>
          virtual void Initialize();

          ///////////////////////////////
          //Constructors
          ///////////////////////////////
          /// <summary>
          /// Creates a new component
          /// </summary>
          /// <param name="owner">the owner of the component</param>
          Component(GameObjects::GameObject * owner);
          /// <summary>
          /// Creates a new component
          /// </summary>
          /// <param name="owner">The owner of the component</param>
          /// <param name="dependencies">a list of dependencies</param>
          Component(GameObjects::GameObject * owner, const std::vector<std::string>& dependencies);
          /// <summary>
          /// Creates a new component
          /// </summary>
          /// <param name="owner">the owner of the new component</param>
          /// <param name="dependencies">a space delimited list of names of components that must be present</param>
          Component(GameObjects::GameObject * owner, const std::string& dependencies);
          virtual ~Component();
        };
      }
    }
  }
}
