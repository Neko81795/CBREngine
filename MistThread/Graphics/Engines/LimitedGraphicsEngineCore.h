#pragma once
#include "../GraphicsEventHandlers.h"
#include "../../Core/Vector2.h"
#include "../../Core/Size2.h"
#include "../../Core/RectangleF.h"
#include "../../Core/GameObjects/Space.h"
#include <string>

#define __ABSTRACT = 0

namespace MistThread
{
  namespace Graphics
  {
    class Bitmap; //forward declaration
    class TextFormat;
    namespace Engines
    {
      using Vector2 = MistThread::Core::Vector2;
      using Size2 = MistThread::Core::Size2;
      using RectangleF = MistThread::Core::RectangleF;

      /// <summary>
      /// All the fun of graphics, without the actual graphics.
      /// This class is abstract
      /// </summary>
      class LimitedGraphicsEngineCore
      {
      public:
        /// <summary>
        /// An event that is called when the device is recreated
        /// </summary>
        GraphicsEventHandler DeviceRecreated;

      protected:

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
        /// creates a text format with the given font name and size
        /// </summary>
        /// <param name="fontName">the name of the font to use</param>
        /// <param name="size">the size of the font</param>
        virtual void CreateTextFormat(const std::string &fontName, float size, TextFormat &format) __ABSTRACT;
        /// <summary>
        /// Gets the center of the window (in pixels)
        /// </summary>
        virtual Vector2 GetWindowCenter() const __ABSTRACT;
        /// <summary>
        /// Gets the size of the window in pixels
        /// </summary>
        virtual Size2 GetWindowBounds() const __ABSTRACT;
        /// <summary>
        /// Gets the center of the window (in pixels)
        /// </summary>
        virtual Vector2 GetWindowCenter() __ABSTRACT;
        /// <summary>
        /// Gets the size of the window in pixels
        /// </summary>
        virtual Size2 GetWindowBounds() __ABSTRACT;
        /// <summary>
        /// Gets the Rectangle that the camera can see at the given zLayer
        /// </summary>
        /// <param name="position">the position of the camera</param>
        /// <param name="zLayer">the zLayer to get the rectangle at</param>
        virtual RectangleF GetWorldViewRectangle(const Core::Vector2 &position, float zLayer) const __ABSTRACT;
        /// <summary>
        /// returns a read only copy of the default text format
        /// </summary>
        virtual const TextFormat &GetDefaultTextFormat() const __ABSTRACT;
        /// <summary>
        /// returns a reference to the default text format
        /// </summary>
        virtual TextFormat &GetDefaultTextFormat() __ABSTRACT;

        /// <summary>
        /// returns the size of the text the string would display
        /// </summary>
        /// <param name="text">the string</param>
        /// <param name="font">the font family</param>
        /// <param name="size">the size of the font (in point)</param>
        virtual Vector2 MeasureString(const std::string &text, const std::string &font, float size) const __ABSTRACT;

        /// <summary>
        /// toggles the full Screen mode
        /// </summary>
        virtual void ToggleFullScreen() __ABSTRACT;

        /// <summary>
        /// Determines whether a point is on the screen or not
        /// </summary>
        /// <param name="point">the point to check</param>
        virtual bool IsPointOnScreen(const Vector2 &point) const;

        /// <summary>
        /// Calculates how far the point is away from the screen (in pixels).
        /// returns 0 if on the screen
        /// </summary>
        /// <param name="point">the point to check</param>
        virtual double DistanceFromSreen(const Vector2 &point) const;

        /// <summary>
        /// returns the size of the text the string would display using the default font
        /// </summary>
        /// <param name="text">the string</param>
        Vector2 MeasureString(const char *text) const;


        virtual ~LimitedGraphicsEngineCore() {}
      };
    }
  }
}
