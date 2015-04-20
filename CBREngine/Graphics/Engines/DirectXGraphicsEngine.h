#pragma once

#pragma comment(lib, "d2d1")

#include "GraphicsEngineCore.h"
#include "..\..\Core\CoreEvents.h"
#include <wrl.h>

#pragma warning(disable: 4838) //disable conversion warnings
#pragma warning(disable: 4458) //disable hiding class members
#include <d2d1.h>
#include <DirectXColors.h>
#include <DirectXMath.h>
#pragma warning(default: 4458) //enable hiding class members
#pragma warning(default: 4838) //enable conversion warnings
#include <dwrite_2.h>


template <typename T>
using ComPtr = Microsoft::WRL::ComPtr<T>;


namespace CBREngine
{
  namespace Core
  {
    class GameWindow;
  }
  namespace Graphics
  {
    namespace Engines
    {
      class DirectXGraphicsEngine : public GraphicsEngineCore
      {
        //variables
      protected:
        ComPtr<ID2D1Factory> Factory;
        ComPtr<ID2D1HwndRenderTarget> RenderTarget;
        ComPtr<ID2D1SolidColorBrush> SolidBrush;


        //methods
      private:

      protected:
        /// <summary>
        /// Sets the default font
        /// </summary>
        virtual void SetDefaultFont(char *font) override;
        /// <summary>
        /// Sets the default font size
        /// </summary>
        virtual void SetDefaultFontSize(double size) override;

        void CreateDeviceResources();
        void CreateDeviceIndependentResources();

        friend static void WindowResized(Core::WindowEvent &evnt);
        friend static void DisplayChanged(Core::WindowEvent &evnt);

      public:
        /// <summary>
        /// Gets the default font
        /// </summary>
        virtual const char *GetDefaultFont() const override;
        /// <summary>
        /// Gets the default font size
        /// </summary>
        virtual double GetDefaultFontSize() const override;
        /// <summary>
        /// Gets the center of the window (in pixels)
        /// </summary>
        virtual Vector2 GetWindowCenter() const override;
        /// <summary>
        /// Gets the size of the window
        /// </summary>
        virtual Size2 GetWindowBounds() const override;
        /// <summary>
        /// returns the size of the text the string would display
        /// </summary>
        /// <param name="text">the string</param>
        /// <param name="font">the font family</param>
        /// <param name="size">the size of the font (in point)</param>
        virtual Vector2 MeasureString(const char *text, const char *font, double size) const override;
        /// <summary>
        /// toggles the full Screen mode
        /// </summary>
        virtual void ToggleFullScreen() override;
        /// <summary>
        /// begins the draw
        /// </summary>
        virtual void BeginDraw() override;
        /// <summary>
        /// clears the screen to the specified color
        /// </summary>
        virtual void Clear(const Color &color) override;
        /// <summary>
        /// ends the draw
        /// </summary>
        virtual void EndDraw() override;
        /// <summary>
        /// Draws the outline of a rectangle
        /// </summary>
        /// <param name="rectangle">The rectangle to draw</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="stroke">The stroke of the lines</param>
        /// <param name="rotation">The rotation of the Rectangle in degrees</param>
        /// <param name="center">The center of the Rectangle</param>
        virtual void DrawRectangle(const Core::RectangleF &rectangle, const Color &color, float stroke, float rotation, const Vector2 &center) override;
        /// <summary>
        /// Draws the outline of an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="size">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        /// <param name="stroke">The stroke of the lines</param>
        /// <param name="rotation">The rotation of the Ellipse</param>
        /// <param name="center">The center of the Ellipse</param>
        virtual void DrawEllipse(const Core::Vector2 &position, const Core::Size2F size, const Color &color, float stroke, float rotation, const Vector2 &center) override;
        /// <summary>
        /// Draws the outline of an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="size">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        /// <param name="stroke">The stroke of the lines</param>
        /// <param name="rotation">The rotation of the Ellipse</param>
        /// <param name="center">The center of the Ellipse</param>
        virtual void FillEllipse(const Core::Vector2 &position, const Core::Size2F size, const Color &color, float rotation, const Vector2 &center) override;

        DirectXGraphicsEngine(Core::GameWindow &gameWindow);
        ~DirectXGraphicsEngine();
      };
    }
  }
}
