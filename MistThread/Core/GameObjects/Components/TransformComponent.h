#pragma once
#include "../../Vector2.h"
#include "../../Size2f.h"
#include "Component.h"

namespace MistThread
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        class TransformComponent : public Component
        {
        private:
          /// <summary>
          /// how far back the object should appear to be
          /// </summary>
          float ZLayer;
        public:
          /// <summary>
          /// the position in game units
          /// </summary>
          Vector2 Position;
          /// <summary>
          /// the scale in game units
          /// </summary>
          Size2F Scale;
          /// <summary>
          /// the rotation in degrees
          /// </summary>
          float Rotation;


          float GetZLayer() const;

          void SetZLayer(float value);
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

          /// <summary>
          /// Creates a new Transform Component
          /// </summary>
          /// <param name="owner">the owner of this component</param>
          TransformComponent(GameObjects::GameObjectBase *owner);
          ~TransformComponent();
        };
      }
    }
  }
}
