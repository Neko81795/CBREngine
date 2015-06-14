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
//Methods
//////////////////////////////////////////////////////////////
      private:
        GameObject& operator =(const GameObject&) {}
      public:
        /// <summary>
        /// Draws all components listening to the draw event
        /// </summary>
        /// <param name="graphics">the graphics engine of the game</param>
        void Draw(Graphics::Engines::GraphicsEngineCore &graphics);
        /// <summary>
        /// compares this object to another for sorting
        /// value will be less than, greater than, or equal to 0.
        /// </summary>
        int CompareTo(const GameObjectBase* other)const override;

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

