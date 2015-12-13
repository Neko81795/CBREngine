#pragma once
#include "Component.h"
#include "DrawEvent.h"
#include "TransformComponent.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        class DrawComponent : public Component
        {
        public:
          enum GeometryType
          {
            Rectangle,
            Ellipse
          };
          enum DrawMode
          {
            Outline,
            Fill
          };

          ///////////////////////////////
          //Variables
          ///////////////////////////////
        public:
          enum GeometryType Type;
          enum DrawMode Mode;
          /// <summary>
          /// the stroke of drawing, only useful in Outline mode
          /// </summary>
          float Stroke;
          Graphics::Color Color;
          TransformComponent *Transform;


          ///////////////////////////////
          //Methods
          ///////////////////////////////
          void Draw(DrawEvent *drawEvent);
          void Initialize() override;

          /// <summary>
          /// Sets up the component from with the given XML Element
          /// </summary>
          /// <param name="element">the element with the data needed to initialize</param>
          virtual void DeSerialize(const IO::XML::XMLElement & element) override;
          /// <summary>
          /// Populates the given XML Element with data for saving
          /// </summary>
          /// <param name="element">the element to fill with data</param>
          virtual void Serialize(IO::XML::XMLElement & element) const override;

          ///////////////////////////////
          //Constructors
          ///////////////////////////////
          DrawComponent(GameObjects::GameObjectBase *owner);
          ~DrawComponent();
        };
      }
    }
  }
}

