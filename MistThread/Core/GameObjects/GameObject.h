#pragma once
#include "GameObjectBase.h"
#include "Components/Component.h"

#include <string>
#include <list>

namespace MistThread
{
  namespace Graphics
  {
    namespace Engines
    {
      class GraphicsEngineCore; //forward declaration
    }
  }
  namespace Core
  {
    namespace GameObjects
    {
      class Space; //forward declaration

      class GameObject : public GameObjectBase
      {
        friend class GameObjects::Space;

//////////////////////////////////////////////////////////////
//Variables
//////////////////////////////////////////////////////////////
      public:
        GameObject *Parent = NULL;
//////////////////////////////////////////////////////////////
//Methods
//////////////////////////////////////////////////////////////
      private:
        GameObject& operator =(const GameObject&) {}
      public:
        /// <summary>
        /// creates a new child
        /// </summary>
        /// <returns> a reference to the new object </returns>
        GameObject& CreateChild();
        /// <summary>
        /// creates a new child at the given relative position
        /// </summary>
        /// <param name="pos">where to spawn the object</param>
        /// <param name="zLayer">the zLayer to spawn the object at</param>
        /// <returns> a reference to the new object </returns>
        GameObject& CreateChildAt(const Vector2 &pos, float zLayer = 0);
        /// <summary>
        /// Finds the first child with the given name. returns NULL if not found
        /// </summary>
        /// <param name="name">the name of the object to find</param>
        /// <exception cref="std::exception">thrown when object doesn't exist</exception>
        GameObject& FindChildByName(const std::string &name);
        /// <summary>
        /// removes the first child with a matching named
        /// </summary>
        /// <param name="name">the name of the child to remove</param>
        void RemoveChildByName(const std::string &name);
        /// <summary>
        /// removes the child with a matching named
        /// </summary>
        /// <param name="id">the ID of the child to remove</param>
        void RemoveChildByID(long long id);
        /// <summary>
        /// Makes the current object the child of the given one
        /// </summary>
        /// <param name="object">the object to become a parent</param>
        void ParentTo(GameObject &object);
        /// <summary>
        /// Removes the current object from the parent and places it in the space
        /// </summary>
        void UnParent();
        /// <summary>
        /// Makes the given object the child of the current one
        /// </summary>
        /// <param name="object">the object to make a child</param>
        void Adopt(GameObject &object);
        /// <summary>
        /// Abandons the child
        /// </summary>
        /// <param name="object">the child to abandon</param>
        void Orphan(GameObject &object);
        /// <summary>
        /// compares this object to another for sorting
        /// value will be less than, greater than, or equal to 0.
        /// </summary>
        int CompareTo(const GameObjectBase* other)const override;
        /// <summary>
        /// Sets up the gameobject from with the given XML Element
        /// </summary>
        /// <param name="element">the element with the data needed to initialize</param>
        virtual void InitializeFromXML(const IO::XML::XMLElement & element);
        /// <summary>
        /// Populates the given XML Element with data for saving
        /// </summary>
        /// <param name="element">the element to fill with data</param>
        virtual void PopulateXML(IO::XML::XMLElement & element) const;

        virtual void Destroy();

//////////////////////////////////////////////////////////////
//Constructors
//////////////////////////////////////////////////////////////
      private:
        GameObject(Core::Game &game, GameObjects::Space &space);
      public:
        virtual ~GameObject();
      };
    }
  }
}

