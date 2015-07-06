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
        class DrawTextComponent : public Component
        {
          ///////////////////////////////
          //Variables
          ///////////////////////////////
        public:
          Graphics::Bitmap *Image;
          TransformComponent *Transform;
          std::string Text;
          Graphics::Color Color;


          ///////////////////////////////
          //Methods
          ///////////////////////////////
        public:
          void Draw(DrawEvent *drawEvent);
          void Initialize() override;


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

