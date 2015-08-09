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

