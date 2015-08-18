#pragma once
#include "Component.h"
#include "../../CoreEvents.h"
#include "TransformComponent.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        class CameraComponent : public Component
        {
          friend class Space;
        private:
          /// <summary>
          /// the scale to apply to the renderer to get the camera to appear correct
          /// </summary>
          float CameraScale;
        public:
          /// <summary>
          /// the number of units tall this camera viewport is
          /// </summary>
          float Size = 20;
          TransformComponent *Transform;

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

          void Initialize() override;

          void WindowResized(WindowEvent * evnt);

          CameraComponent(GameObjects::GameObjectBase * owner);

          ~CameraComponent();
        };
      }
    }
  }
}

