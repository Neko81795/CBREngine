#pragma once
#include "../GraphicsEventHandlers.h"
#include "../../Core/Vector2.h"
#include "../../Core/Size2.h"
#include <string>

#define __ABSTRACT = 0

namespace MistThread
{
  namespace Graphics
  {
    namespace Engines
    {
      using Vector2 = MistThread::Core::Vector2;
      using Size2 = MistThread::Core::Size2;

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
        /// <summary>
        /// Sets the default font
        /// </summary>
        virtual void SetDefaultFont(char *font) __ABSTRACT;
        /// <summary>
        /// Sets the default font size
        /// </summary>
        virtual void SetDefaultFontSize(double size) __ABSTRACT;

      public:

        /// <summary>
        /// Gets the default font
        /// </summary>
        virtual const char *GetDefaultFont() const __ABSTRACT;
        /// <summary>
        /// Gets the default font size
        /// </summary>
        virtual double GetDefaultFontSize() const __ABSTRACT;
        /// <summary>
        /// Gets the center of the window (in pixels)
        /// </summary>
        virtual Vector2 GetWindowCenter() const __ABSTRACT;
        /// <summary>
        /// Gets the size of the window
        /// </summary>
        virtual Size2 GetWindowBounds() const __ABSTRACT;

        /// <summary>
        /// returns the size of the text the string would display
        /// </summary>
        /// <param name="text">the string</param>
        /// <param name="font">the font family</param>
        /// <param name="size">the size of the font (in point)</param>
        virtual Vector2 MeasureString(const char *text, const char *font, double size) const __ABSTRACT;

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
