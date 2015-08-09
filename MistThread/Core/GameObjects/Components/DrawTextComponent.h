#pragma once
#include "Component.h"
#include "DrawEvent.h"
#include "TransformComponent.h"
#include "../../../Graphics/TextFormat.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        class DrawTextComponent : public Component
        {
          ///////////////////////////////
          //Variables
          ///////////////////////////////
        public:
          TransformComponent *Transform;
          std::string Text;
          Graphics::Color Color;
          Graphics::TextFormat Font;


          ///////////////////////////////
          //Methods
          ///////////////////////////////
        public:
          void Draw(DrawEvent *drawEvent);
          void Initialize() override;

          /// <summary>
          /// Sets up the component from with the given XML Element
          /// </summary>
          /// <param name="element">the element with the data needed to initialize</param>
          virtual void InitializeFromXML(const IO::XML::XMLElement & element) override;
          /// <summary>
          /// Populates the given XML Element with data for saving
          /// </summary>
          /// <param name="element">the element to fill with data</param>
          virtual void PopulateXML(IO::XML::XMLElement & element) const override;

          ///////////////////////////////
          //Constructors
          ///////////////////////////////
        public:
          DrawTextComponent(GameObjects::GameObjectBase *owner);
          ~DrawTextComponent();
        };
      }
    }
  }
}

