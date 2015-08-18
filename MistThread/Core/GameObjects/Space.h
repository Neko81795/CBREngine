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
        GameObjects::GameObjectBase *Camera;
//////////////////////////////////////////////////////////////
//Methods
//////////////////////////////////////////////////////////////
      private:
        Space& operator=(const Space&) {}
        /// <summary>
        /// Loads a level from the given XML element
        /// </summary>
        /// <param name="element">the element with the level info</param>
        void LoadXML(const IO::XML::XMLElement &element);
        /// <summary>
        /// saves the current level setup to the given XML element
        /// </summary>
        /// <param name="element">the element to store the info in</param>
        void SaveXML(IO::XML::XMLElement &element) const;

        void SetCamera();
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
        /// removes the object with a matching ID
        /// </summary>
        /// <param name="id">the ID of the object to remove</param>
        void RemoveObjectByID(long long id);
        /// <summary>
        /// compares this object to another for sorting
        /// value will be less than, greater than, or equal to 0.
        /// </summary>
        int CompareTo(const GameObjectBase* other)const override;
        /// <summary>
        /// Loads the level file at the given path
        /// </summary>
        /// <param name="path">the path to the file to load</param>
        void LoadLevel(const std::string &path);
        /// <summary>
        /// Saves the level to the file at the given path
        /// </summary>
        /// <param name="path">the path to save to</param>
        void SaveLevel(const std::string &path) const;
        /// <summary>
        /// Sets the layer level for space to determine draw order
        /// </summary>
        void SetSpaceLayer(int layer);
        /// <summary>
        /// returns the layer this level draws on
        /// </summary>
        int GetSpaceLayer() const;

        void Draw(Graphics::Engines::GraphicsEngineCore &graphics, GameObjectBase* caller = NULL) override;

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

