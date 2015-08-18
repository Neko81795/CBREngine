#pragma once
#include "LimitedGraphicsEngineCore.h"
#include "../Color.h"
#include "../../Core/RectangleF.h"
#include <atomic>

namespace MistThread
{
  namespace Graphics
  {
    namespace Engines
    {
      class GraphicsEngineCore : public LimitedGraphicsEngineCore
      {
//////////////////////////////////////////////////////////////
//Variables
//////////////////////////////////////////////////////////////
      protected:
        std::atomic_flag Lock;
      public:
        float CameraZ = 30;
        Vector2 CameraPos;
        float CameraScale;
        float CameraRotation;
        bool ZLayeringAffectsScale = true;
//////////////////////////////////////////////////////////////
//Methods
//////////////////////////////////////////////////////////////
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
        /// <param name="zLayer">The zlayer of the bitmap</param>
        virtual void DrawRectangle(const Core::RectangleF &rectangle, const Color &color, float stroke, float rotation, const Vector2 &center, float zLayer = 0) __ABSTRACT;
        /// <summary>
        /// Draws the outline of an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="position">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        /// <param name="stroke">The stroke of the lines</param>
        /// <param name="rotation">The rotation of the Ellipse</param>
        /// <param name="center">The center of the Ellipse</param>
        /// <param name="zLayer">The zlayer of the bitmap</param>
        virtual void DrawEllipse(const Core::Vector2 &posistion, const Core::Size2F size, const Color &color, float stroke, float rotation, const Vector2 &center, float zLayer = 0)__ABSTRACT;
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
        /// <param name="zLayer">The zlayer of the bitmap</param>
        virtual void FillEllipse(const Core::Vector2 &position, const Core::Size2F size, const Color &color, float rotation, const Vector2 &center, float zLayer = 0) __ABSTRACT;
        /// <summary>
        /// Draws a rectangle
        /// </summary>
        /// <param name="rectangle">The rectangle to draw</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="rotation">The rotation of the Rectangle</param>
        /// <param name="center">The center of the Rectangle</param>
        /// <param name="zLayer">The zlayer of the bitmap</param>
        virtual void FillRectangle(const Core::RectangleF &rectangle, const Color &color, float rotation, const Vector2 &center, float zLayer = 0) __ABSTRACT;
        /// <summary>
        /// Draws a string of text to the screen
        /// </summary>
        /// <param name="text">The string to draw</param>
        /// <param name="font">The font to use to draw the string</param>
        /// <param name="bounds">the rectangle to draw the string in</param>
        /// <param name="position">where in the world to draw the string</param>
        /// <param name="color">the color to draw the string</param>
        /// <param name="rotation">the rotation of the text</param>
        /// <param name="zLayer">the zLayer at which to draw the text</param>
        virtual void DrawString(const std::string &text, const TextFormat &font, const Core::RectangleF &bounds, const Vector2 &position, const Color &color, float rotation, float zLayer = 0) __ABSTRACT;
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
        void DrawRectangle(const Core::Vector2 &position, const Core::Size2F &size, const Color &color, float stroke, float rotation, float zLayer = 0);
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
        void FillRectangle(const Core::Vector2 &position, const Core::Size2F &size, const Color &color, float rotation, float zLayer = 0);
        /// <summary>
        /// Draws a string of text to the screen
        /// </summary>
        /// <param name="text">The string to draw</param>
        /// <param name="font">The font to use to draw the string</param>
        /// <param name="position">where in the world to draw the string</param>
        /// <param name="color">the color to draw the string</param>
        /// <param name="rotation">the rotation of the text</param>
        /// <param name="zLayer">the zLayer at which to draw the text</param>
        virtual void DrawString(const std::string &text, const TextFormat &font, const Vector2 &position, const Color &color, float rotation = 0, float zLayer = 0);
        /// <summary>
        /// Draws a string of text to the screen using the default font
        /// </summary>
        /// <param name="text">The string to draw</param>
        /// <param name="position">where in the world to draw the string</param>
        /// <param name="color">the color to draw the string</param>
        /// <param name="rotation">the rotation of the text</param>
        /// <param name="zLayer">the zLayer at which to draw the text</param>
        virtual void DrawString(const std::string &text, const Vector2 &position, const Color &color, float rotation = 0, float zLayer = 0);


//////////////////////////////////////////////////////////////
//Constructors
//////////////////////////////////////////////////////////////
        virtual ~GraphicsEngineCore() {}
      };
    }
  }
}
