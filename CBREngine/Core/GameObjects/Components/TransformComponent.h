#pragma once
#include "../../Vector2.h"
#include "../../Size2f.h"
#include "Component.h"

namespace CBREngine
{
  namespace Core
  {
    namespace GameObjects
    {
      namespace Components
      {
        class TransformComponent : public Component
        {
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

          /// <summary>
          /// Creates a new Transform Component
          /// </summary>
          /// <param name="owner">the owner of this component</param>
          TransformComponent(GameObjects::GameObject *owner);
          ~TransformComponent();
        };
      }
    }
  }
}
