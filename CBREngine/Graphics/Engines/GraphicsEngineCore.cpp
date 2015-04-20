#include "GraphicsEngineCore.h"


namespace CBREngine
{
  namespace Graphics
  {
    namespace Engines
    {
      void GraphicsEngineCore::DrawRectangle(const Core::RectangleF & rectangle, const Color & color)
      {
        DrawRectangle(rectangle, color, 1, 0, Vector2());
      }

      void GraphicsEngineCore::DrawRectangle(const Core::RectangleF & rectangle, const Color & color, float stroke)
      {
        DrawRectangle(rectangle, color, stroke, 0, Vector2());
      }

      void GraphicsEngineCore::DrawRectangle(const Core::RectangleF & rectangle, const Color & color, float stroke, float rotation)
      {
        DrawRectangle(rectangle, color, stroke, rotation, Vector2());
      }
    }
  }
}
