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
        /// Removes the component with the given name
        /// </summary>
        /// <param name="name">The name of the component to remove</param>
        void RemoveComponentByName(const std::string& name);
        /// <summary>
        /// Draws all components listening to the draw event
        /// </summary>
        /// <param name="graphics">the graphics engine of the game</param>
        void Draw(Graphics::Engines::GraphicsEngineCore &graphics);

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

