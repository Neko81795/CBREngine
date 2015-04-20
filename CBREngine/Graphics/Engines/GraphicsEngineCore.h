#pragma once
#include "LimitedGraphicsEngineCore.h"
#include "../Color.h"
#include "../../Core/RectangleF.h"

namespace CBREngine
{
  namespace Graphics
  {
    namespace Engines
    {
      class GraphicsEngineCore : public LimitedGraphicsEngineCore
      {
      public:
        /// <summary>
        /// begins the draw
        /// </summary>
        virtual void BeginDraw() __ABSTRACT;
        /// <summary>
        /// clears the screen to the specified color
        /// </summary>
        virtual void Clear(const Color &color) __ABSTRACT;
        /// <summary>
        /// Draws the outline of a rectangle
        /// </summary>
        /// <param name="rectangle">The rectangle to draw</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="stroke">The stroke of the lines</param>
        /// <param name="rotation">The rotation of the Rectangle</param>
        /// <param name="center">The center of the Rectangle</param>
        virtual void DrawRectangle(const Core::RectangleF &rectangle, const Color &color, float stroke, float rotation, const Vector2 &center) __ABSTRACT;
        /// <summary>
        /// Draws the outline of an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="position">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        /// <param name="stroke">The stroke of the lines</param>
        /// <param name="rotation">The rotation of the Ellipse</param>
        /// <param name="center">The center of the Ellipse</param>
        virtual void DrawEllipse(const Core::Vector2 &posistion, const Core::Size2F size, const Color &color, float stroke, float rotation, const Vector2 &center)__ABSTRACT;

        /// <summary>
        /// ends the draw
        /// </summary>
        virtual void EndDraw() __ABSTRACT;

        /// <summary>
        /// Draws the outline of an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="size">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        /// <param name="stroke">The stroke of the lines</param>
        /// <param name="rotation">The rotation of the Ellipse</param>
        /// <param name="center">The center of the Ellipse</param>
        virtual void FillEllipse(const Core::Vector2 &position, const Core::Size2F size, const Color &color, float rotation, const Vector2 &center) __ABSTRACT;







        /// <summary>
        /// Draws the outline of a rectangle
        /// </summary>
        /// <param name="rectangle">The rectangle to draw</param>
        /// <param name="color">The color of the rectangle</param>
        void DrawRectangle(const Core::RectangleF &rectangle, const Color &color);
        /// <summary>
        /// Draws the outline of a rectangle
        /// </summary>
        /// <param name="rectangle">The rectangle to draw</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="width">The width of the outline</param>
        void DrawRectangle(const Core::RectangleF &rectangle, const Color &color, float stroke);
        /// <summary>
        /// Draws the outline of a rectangle
        /// </summary>
        /// <param name="rectangle">The rectangle to draw</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="width">The width of the outline</param>
        /// <param name="rotation">The rotation of the Rectangle</param>
        void DrawRectangle(const Core::RectangleF &rectangle, const Color &color, float stroke, float rotation);

        virtual ~GraphicsEngineCore() {}
      };
    }
  }
}
