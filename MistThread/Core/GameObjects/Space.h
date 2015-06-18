#pragma once
#include "GameObject.h"
#include "GameObjectBase.h"
#include "../Game.h"
#include "../GameTime.h"
#include "../../Graphics/Engines/LimitedGraphicsEngineCore.h"
#include <string>
#include <list>

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      class Space : public GameObjectBase
      {
        friend class Core::Game;
//////////////////////////////////////////////////////////////
//Variables
//////////////////////////////////////////////////////////////
      protected:
        int SpaceLayer;
      public:
        Core::GameTime GameTime;
//////////////////////////////////////////////////////////////
//Methods
//////////////////////////////////////////////////////////////
      private:
        Space& operator=(const Space&) {}
      public:
        /// <summary>
        /// Updates all components listening to the update event
        /// </summary>
        /// <param name="gameTime">the current game time</param>
        void Update();
        /// <summary>
        /// creates a new game object in the space
        /// </summary>
        /// <returns> a reference to the new object </returns>
        GameObject& CreateObject();
        /// <summary>
        /// creates a new game object in the space at the given position
        /// </summary>
        /// <param name="pos">where to spawn the object</param>
        /// <param name="zLayer">the zLayer to spawn the object at</param>
        /// <returns> a reference to the new object </returns>
        GameObject& CreateObjectAt(const Vector2 &pos, float zLayer = 0);
        /// <summary>
        /// Finds the first object with the given name. returns NULL if not found
        /// </summary>
        /// <param name="name">the name of the object to find</param>
        /// <exception cref="std::exception">thrown when object doesn't exist</exception>
        GameObject& FindObjectByName(const std::string &name);
        /// <summary>
        /// Finds all objects with the given name.
        /// </summary>
        /// <param name="name">the name of the objects to find</param>
        const std::list<GameObject*> FindObjectsByName(const std::string &name);
        /// <summary>
        /// removes the first object with a matching named
        /// </summary>
        /// <param name="name">the name of the object to remove</param>
        void RemoveObjectByName(const std::string &name);
        /// <summary>
        /// compares this object to another for sorting
        /// value will be less than, greater than, or equal to 0.
        /// </summary>
        int CompareTo(const GameObjectBase* other)const override;

//////////////////////////////////////////////////////////////
//Constructors
//////////////////////////////////////////////////////////////
      private:
        Space(Core::Game &game);
      public:
        ~Space();
      };
    }
  }
}

