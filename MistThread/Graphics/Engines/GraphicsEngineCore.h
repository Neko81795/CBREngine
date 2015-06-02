#pragma once
#include "LimitedGraphicsEngineCore.h"
#include "../Color.h"
#include "../../Core/RectangleF.h"
#include <atomic>

namespace MistThread
{
  namespace Graphics
  {
    class Bitmap; //forward declaration
    namespace Engines
    {
      class GraphicsEngineCore : public LimitedGraphicsEngineCore
      {
        //variables
      protected:
        std::atomic_flag Lock;
      public:
        //methods
      public:
        /// <summary>
        /// loads a bitmap from the specified file
        /// </summary>
        /// <param name="path"> the path to the image file </param>
        /// <param name="bitmap"> the bitmap to store the loaded image in </param>
        virtual void LoadBitmapFromFile(const std::string &path, Bitmap & bitmap) __ABSTRACT;
        /// <summary>
        /// Reloads the given bitmap
        /// </summary>
        virtual void ReloadBitmap(Bitmap &bitmap) __ABSTRACT;
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
        /// Draws a bitmap to the screen
        /// </summary>
        /// <param name="image">The bitmap to draw</param>
        /// <param name="position">Where to draw it</param>
        /// <param name="opacity">The opacity of the bitmap</param>
        /// <param name="center">The center of the bitmap</param>
        /// <param name="rotation">The rotation of the bitmap</param>
        /// <param name="scale">The Scaling of the bitmap</param>
        /// <param name="source">The Rectangle of the image to use</param>
        /// <param name="zLayer">The zlayer of the bitmap</param>
        virtual void DrawBitmap(const Bitmap &image, const Vector2 &position, float opacity, const Vector2 &center, float rotation, const Core::Size2F &scale, const Core::RectangleF *source = NULL, float zLayer = 0) __ABSTRACT;
        /// <summary>
        /// Draws the an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="size">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        /// <param name="rotation">The rotation of the Ellipse</param>
        /// <param name="center">The center of the Ellipse</param>
        virtual void FillEllipse(const Core::Vector2 &position, const Core::Size2F size, const Color &color, float rotation, const Vector2 &center) __ABSTRACT;
        /// <summary>
        /// Draws a rectangle
        /// </summary>
        /// <param name="rectangle">The rectangle to draw</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="rotation">The rotation of the Rectangle</param>
        /// <param name="center">The center of the Rectangle</param>
        virtual void FillRectangle(const Core::RectangleF &rectangle, const Color &color, float rotation, const Vector2 &center) __ABSTRACT;
        /// <summary>
        /// ends the draw
        /// </summary>
        virtual void EndDraw() __ABSTRACT;
        

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
        /// <param name="stroke">The width of the outline</param>
        void DrawRectangle(const Core::RectangleF &rectangle, const Color &color, float stroke);
        /// <summary>
        /// Draws the outline of a rectangle
        /// </summary>
        /// <param name="rectangle">The rectangle to draw</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="stroke">The width of the outline</param>
        /// <param name="rotation">The rotation of the Rectangle</param>
        void DrawRectangle(const Core::RectangleF &rectangle, const Color &color, float stroke, float rotation);
        /// <summary>
        /// Draws the outline of a rectangle centered on the position
        /// </summary>
        /// <param name="position">the position of the rectangle</param>
        /// <param name="size">the dimensions of the rectangle</param>
        /// <param name="color">The color of the rectangle</param>
        void DrawRectangle(const Core::Vector2 &position, const Core::Size2F &size, const Color &color);
        /// <summary>
        /// Draws the outline of a rectangle centered on the position
        /// </summary>
        /// <param name="position">the position of the rectangle</param>
        /// <param name="size">the dimensions of the rectangle</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="stroke">The width of the outline</param>
        void DrawRectangle(const Core::Vector2 &position, const Core::Size2F &size, const Color &color, float stroke);
        /// <summary>
        /// Draws the outline of a rectangle centered on the position
        /// </summary>
        /// <param name="position">the position of the rectangle</param>
        /// <param name="size">the dimensions of the rectangle</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="stroke">The width of the outline</param>
        /// <param name="rotation">The rotation of the Rectangle</param>
        void DrawRectangle(const Core::Vector2 &position, const Core::Size2F &size, const Color &color, float stroke, float rotation);
        /// <summary>
        /// Draws the outline of an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="position">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        void DrawEllipse(const Core::Vector2 &posistion, const Core::Size2F size, const Color &color);
        /// <summary>
        /// Draws the outline of an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="position">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        /// <param name="stroke">The stroke of the lines</param>
        void DrawEllipse(const Core::Vector2 &posistion, const Core::Size2F size, const Color &color, float stroke);
        /// <summary>
        /// Draws the outline of an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="position">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        /// <param name="stroke">The stroke of the lines</param>
        /// <param name="rotation">The rotation of the Ellipse</param>
        void DrawEllipse(const Core::Vector2 &posistion, const Core::Size2F size, const Color &color, float stroke, float rotation);
        /// <summary>
        /// Draws the an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="size">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        void FillEllipse(const Core::Vector2 &position, const Core::Size2F size, const Color &color);
        /// <summary>
        /// Draws the an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="size">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        /// <param name="rotation">The rotation of the Ellipse</param>
        void FillEllipse(const Core::Vector2 &position, const Core::Size2F size, const Color &color, float rotation);
        /// <summary>
        /// Draws a rectangle
        /// </summary>
        /// <param name="rectangle">The rectangle to draw</param>
        /// <param name="color">The color of the rectangle</param>
        void FillRectangle(const Core::RectangleF &rectangle, const Color &color);
        /// <summary>
        /// Draws a rectangle
        /// </summary>
        /// <param name="rectangle">The rectangle to draw</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="rotation">The rotation of the Rectangle</param>
        void FillRectangle(const Core::RectangleF &rectangle, const Color &color, float rotation);
        /// <summary>
        /// Draws a rectangle Centered on the position
        /// </summary>
        /// <param name="position">the position of the rectangle</param>
        /// <param name="size">the dimensions of the rectangle</param>
        /// <param name="color">The color of the rectangle</param>
        void FillRectangle(const Core::Vector2 &position, const Core::Size2F &size, const Color &color);
        /// <summary>
        /// Draws a rectangle Centered on the position
        /// </summary>
        /// <param name="position">the position of the rectangle</param>
        /// <param name="size">the dimensions of the rectangle</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="rotation">The rotation of the Rectangle</param>
        void FillRectangle(const Core::Vector2 &position, const Core::Size2F &size, const Color &color, float rotation);

        virtual ~GraphicsEngineCore() {}
      };
    }
  }
}