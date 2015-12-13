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
        private:
          std::string ImagePath;
        public:
          Graphics::Bitmap *Image;
          TransformComponent *Transform;
          float Opacity;


          ///////////////////////////////
          //Methods
          ///////////////////////////////
        public:
          void Draw(DrawEvent *drawEvent);
          void Initialize() override;

          void LoadImageFromFile(const std::string &path);
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
        public:
          DrawBitmapComponent(GameObjects::GameObjectBase *owner);
          ~DrawBitmapComponent() {}
        };
      }
    }
  }
}

