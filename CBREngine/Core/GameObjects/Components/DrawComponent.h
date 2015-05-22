#pragma once
#include "Component.h"
#include "DrawEvent.h"
#include "TransformComponent.h"

namespace CBREngine
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
            Elipse
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

          ///////////////////////////////
          //Constructors
          ///////////////////////////////
          DrawComponent(GameObjects::GameObject *owner);
          ~DrawComponent();
        };
      }
    }
  }
}

