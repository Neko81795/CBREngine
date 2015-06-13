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
      public:
        Graphics::Engines::LimitedGraphicsEngineCore *pGraphics;
        std::list<GameObject> Objects;

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
        void Update(const GameTime &gameTime);
        /// <summary>
        /// creates a new game object in the space
        /// </summary>
        /// <returns> a reference to the new object </returns>
        GameObject& CreateObject();
        /// <summary>
        /// creates a new game object in the space at the given position
        /// </summary>
        /// <param name="pos">where to spawn the object</param>
        /// <returns> a reference to the new object </returns>
        GameObject& CreateObjectAt(Vector2 pos);

//////////////////////////////////////////////////////////////
//Constructors
//////////////////////////////////////////////////////////////
      private:
        Space(Core::Game &game, Graphics::Engines::LimitedGraphicsEngineCore *graphics);
      public:
        ~Space();
      };
    }
  }
}

