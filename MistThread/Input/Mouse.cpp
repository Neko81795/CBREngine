#include "Mouse.h"


namespace MistThread
{
  namespace Input
  {
    MouseState Mouse::Current_;
    MouseState Mouse::Last_;
    const MouseState& Mouse::Current = Current_;
    const MouseState& Mouse::Last = Last_;

    bool Mouse::LeftButtonPressed()
    {
      return Current.LeftButtonDown && !Last.LeftButtonDown;
    }

    bool Mouse::MiddleButtonPressed()
    {
      return Current.MiddleButtonDown && !Last.MiddleButtonDown;
    }

    bool Mouse::RightButtonPressed()
    {
      return Current.RightButtonDown && !Last.RightButtonDown;
    }

    long long Mouse::Scrolled()
    {
      return Current.ScrollWheel - Last.ScrollWheel;
    }

    Vector2 Mouse::DistanceMoved()
    {
      return Current.Position - Last.Position;
    }

    bool  Mouse::HasMoved()
    {
      Vector2 dist = DistanceMoved();
      if(dist.X)
        return true;
      if(dist.Y)
        return true;
      return false;
    }
  }
}
