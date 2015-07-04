#pragma once
#include "../Core/Vector2.h"

using Vector2 = MistThread::Core::Vector2;

namespace MistThread
{
  namespace Input
  {
    class MouseState
    {
    public:
      bool LeftButtonDown;
      bool MiddleButtonDown;
      bool RightButtonDown;
      long long ScrollWheel;
      Vector2 Position;

    public:
      Vector2 PositionInGameWorld(const Vector2& camera, float cameraZ, Vector2 windowCenter, float zLayer) const;
    };
  }
}
