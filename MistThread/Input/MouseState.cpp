#include "MouseState.h"


namespace MistThread
{
  namespace Input
  {
    Vector2 MouseState::PositionInGameWorld(const Vector2& camera, float cameraZ, Vector2 windowCenter, float zLayer) const
    {
      float addscale = 1 / (-(zLayer + cameraZ) / 30);
      return ((Position - windowCenter) / addscale) + camera;
    }
  }
}
