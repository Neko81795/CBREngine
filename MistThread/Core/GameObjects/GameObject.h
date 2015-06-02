#pragma once
#include "../Eventful.h"
#include "Components/Component.h"

#include <string>
#include <list>

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      class Space; //forward declaration
      class GameObject : public Eventful
      {
        friend class GameObjects::Space;
        ///////////////////////////////
        //Variables
        ///////////////////////////////
      private:
        std::list<Components::Component*> _components;

      public:
        static long long Count;

        long long ID;
        std::string Name;
        GameObjects::Space &Space;
        Core::Game &Game;
        //////////////////////////////
        //Methods
        //////////////////////////////
      private:
        GameObject& operator =(const GameObject&) {}
      public:
        const std::list<Components::Component*>& GetComponents();
        Components::Component* GetComponentByName(std::string name);

        template <typename CType>
        CType& AddComponent();

        /// <summary>
        /// Removes the component with the given name
        /// </summary>
        /// <param name="name">The name of the component to remove</param>
        void RemoveComponentByName(const std::string& name);

        ///////////////////////////////
        //Constructors
        ///////////////////////////////
      private:
        GameObject(Core::Game &game, GameObjects::Space &space);
      public:
        virtual ~GameObject();
      };


      /// <summary>
      /// Adds the component of the given type
      /// </summary>
      /// <typeParam name="CType"> The type of the component to add </typeParam>
      /// <example> obj.AddComponent[DrawComponent]() </example>
      /// <exception cref="std::exception"> thrown if needed dependencies don't exist </exception>
      template <typename CType>
      CType& GameObject::AddComponent()
      {
        CType *ctypeptr = new CType(this);
        Components::Component *ptr = ctypeptr;
        for (const std::string &dep : ptr->Dependencies)
        {
          bool found = false;
          for (const Components::Component* current : _components)
          {
            if (current->Name == dep)
            {
              found = true;
              break;
            }
          }
          if (!found)
            throw new std::exception("Component Dependency could not be found"); //TODO add what component was not found
        }

        _components.push_back(ptr);
        return *ctypeptr;
      }
    }
  }
}

