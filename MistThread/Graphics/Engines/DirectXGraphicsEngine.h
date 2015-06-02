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
#include <wincodec.h>




namespace MistThread
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
        template <typename T>
        using ComPtr = Microsoft::WRL::ComPtr<T>;

        //variables
      protected:
        ComPtr<ID2D1Factory> Factory;
        ComPtr<ID2D1HwndRenderTarget> RenderTarget;
        ComPtr<IWICImagingFactory> ImageFactory;
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

        void WindowResized(Core::WindowEvent & evnt);
        void DisplayChanged(Core::WindowEvent &evnt);

      public:
        /// <summary>
        /// loads a bitmap from the specified file
        /// </summary>
        /// <param name="path"> the path to the image file </param>
        /// <param name="bitmap"> the bitmap to store the loaded image in </param>
        virtual void LoadBitmapFromFile(const std::string &path, Bitmap &bitmap);
        /// <summary>
        /// Reloads the given bitmap
        /// </summary>
        virtual void ReloadBitmap(Bitmap &bitmap);
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
        virtual void DrawBitmap(const Bitmap &image, const Vector2 &position, float opacity, const Vector2 &center, float rotation, const Core::Size2F &scale, const Core::RectangleF *source = NULL, float zLayer = 0) override;
        /// <summary>
        /// Draws the an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="size">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        /// <param name="rotation">The rotation of the Ellipse</param>
        /// <param name="center">The center of the Ellipse</param>
        virtual void FillEllipse(const Core::Vector2 &position, const Core::Size2F size, const Color &color, float rotation, const Vector2 &center) override;
        /// <summary>
        /// Draws a rectangle
        /// </summary>
        /// <param name="rectangle">The rectangle to draw</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="rotation">The rotation of the Rectangle</param>
        /// <param name="center">The center of the Rectangle</param>
        virtual void FillRectangle(const Core::RectangleF &rectangle, const Color &color, float rotation, const Vector2 &center) override;

        DirectXGraphicsEngine(Core::GameWindow &gameWindow);
        ~DirectXGraphicsEngine();
      };
    }
  }
}
