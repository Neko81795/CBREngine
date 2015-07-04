#pragma once
#include "MouseState.h"

namespace MistThread
{
  namespace Input
  {
    class Mouse
    {
    private:
      static MouseState Current_;
      static MouseState Last_;
    public:
      /// <summary>
      /// Gets a read-only copy of the current mouse state
      /// </summary>
      static const MouseState& Current;
      /// <summary>
      /// Gets a read-only copy of the mouse state from the last game loop
      /// </summary>
      static const MouseState& Last;

    public:
      /// <summary>
      /// Lets you know if the left mouse button was just pressed
      /// </summary>
      static bool LeftButtonPressed();
      /// <summary>
      /// Lets you know if the middle mouse button was just pressed
      /// </summary>
      static bool MiddleButtonPressed();
      /// <summary>
      /// Lets you know if the right mouse button was just pressed
      /// </summary>
      static bool RightButtonPressed();
      /// <summary>
      /// how many scroll ticks the wheel has turned
      /// </summary>
      static long long Scrolled();
      /// <summary>
      /// how far the mouse has moved since the last game loop
      /// </summary>
      static Vector2 DistanceMoved();
      /// <summary>
      /// true if the mouse has moved since the last game loop
      /// </summary>
      static bool  HasMoved();
    };
  }
}
