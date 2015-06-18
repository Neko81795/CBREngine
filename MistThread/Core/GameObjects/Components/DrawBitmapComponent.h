#pragma once
#pragma once
#include "Component.h"
#include "DrawEvent.h"
#include "TransformComponent.h"
#include "../../../Graphics/Bitmap.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        class DrawBitmapComponent : public Component
        {

          ///////////////////////////////
          //Variables
          ///////////////////////////////
        public:
          Graphics::Bitmap *Image;
          TransformComponent *Transform;


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
          DrawBitmapComponent(GameObjects::GameObjectBase *owner);
          ~DrawBitmapComponent() {}
        };
      }
    }
  }
}

