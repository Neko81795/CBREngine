#include "LimitedGraphicsEngineCore.h"
#include "../TextFormat.h"

namespace MistThread
{
  namespace Graphics
  {
    namespace Engines
    {
      bool LimitedGraphicsEngineCore::IsPointOnScreen(const Vector2 &point) const
      {
        if (point.X < 0)
          return false;
        if (point.X > GetWindowBounds().Width)
          return false;

        if (point.Y < 0)
          return false;
        if (point.Y > GetWindowBounds().Height)
          return false;

        return true;
      }

      double LimitedGraphicsEngineCore::DistanceFromSreen(const Vector2 & point) const
      {
        Vector2 reference;

        if (IsPointOnScreen(point))
          return 0;

        if (point.X < 0)
          reference.X = 0;
        else if (point.X > GetWindowBounds().Width)
          reference.X = (float)GetWindowBounds().Width;
        else
          reference.X = point.X;

        if (point.Y < 0)
          reference.Y = 0;
        else if (point.Y > GetWindowBounds().Height)
          reference.Y = (float)GetWindowBounds().Height;
        else
          reference.Y = point.Y;

        return point.DistanceTo(reference);
      }

      Vector2 LimitedGraphicsEngineCore::MeasureString(const char * text) const
      {
        return MeasureString(text, GetDefaultTextFormat().GetFont(), GetDefaultTextFormat().GetSize());
      }
    }
  }
}
