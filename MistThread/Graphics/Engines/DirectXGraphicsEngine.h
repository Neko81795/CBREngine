#pragma once

#pragma comment(lib, "d2d1")
#pragma comment(lib, "dwrite")

#include "GraphicsEngineCore.h"
#include "../../Core/CoreEvents.h"
#include "../TextFormat.h"
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

//////////////////////////////////////////////////////////////
//Variables
//////////////////////////////////////////////////////////////
      private:
        Core::Delegate<Core::WindowEvent &> *DisplayChangedCallback;
        Core::Delegate<Core::WindowEvent &> *ResizeCallback;
        Core::GameWindow &Window;
      protected:
        ComPtr<ID2D1Factory> Factory;
        ComPtr<ID2D1HwndRenderTarget> RenderTarget;
        ComPtr<IWICImagingFactory> ImageFactory;
        ComPtr<IDWriteFactory> TextFactory;
        ComPtr<ID2D1SolidColorBrush> SolidBrush;
        TextFormat DefaultTextFormat;


//////////////////////////////////////////////////////////////
//Methods
//////////////////////////////////////////////////////////////
      private:
        float ConvertDIPToPoint(float DIPUnits);
        float ConvertPointToDIP(float point);
      protected:
        void CreateDeviceResources();
        void CreateDeviceIndependentResources();

        void WindowResized(Core::WindowEvent & evnt);
        void DisplayChanged(Core::WindowEvent &evnt);

      public:
        /// <summary>
        /// returns a read only copy of the default text format
        /// </summary>
        virtual const TextFormat &GetDefaultTextFormat() const override;
        /// <summary>
        /// returns a reference to the default text format
        /// </summary>
        virtual TextFormat &GetDefaultTextFormat() override;
        /// <summary>
        /// loads a bitmap from the specified file
        /// </summary>
        /// <param name="path"> the path to the image file </param>
        /// <param name="bitmap"> the bitmap to store the loaded image in </param>
        /// <exception cref="std::exception"> thrown when the image fails to load </exception>
        virtual void LoadBitmapFromFile(const std::string &path, Bitmap &bitmap);
        /// <summary>
        /// Reloads the given bitmap
        /// </summary>
        /// <exception cref="std::exception"> thrown when the image fails to load </exception>
        virtual void ReloadBitmap(Bitmap &bitmap);
        /// <summary>
        /// creates a text format with the given font name and size
        /// </summary>
        /// <param name="fontName">the name of the font to use</param>
        /// <param name="size">the size of the font</param>
        virtual void CreateTextFormat(const std::string &fontName, float size, TextFormat &format);
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
        virtual Vector2 MeasureString(const std::string &text, const std::string &font, float size) const override;
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
        /// <param name="zLayer">The zlayer of the bitmap</param>
        virtual void DrawRectangle(const Core::RectangleF &rectangle, const Color &color, float stroke, float rotation, const Vector2 &center, float zLayer = 0) override;
        /// <summary>
        /// Draws the outline of an Ellipse
        /// </summary>
        /// <param name="position">Where to draw</param>
        /// <param name="size">the size of the Ellipse</param>
        /// <param name="color">The color to draw</param>
        /// <param name="stroke">The stroke of the lines</param>
        /// <param name="rotation">The rotation of the Ellipse</param>
        /// <param name="center">The center of the Ellipse</param>
        /// <param name="zLayer">The zlayer of the bitmap</param>
        virtual void DrawEllipse(const Core::Vector2 &position, const Core::Size2F size, const Color &color, float stroke, float rotation, const Vector2 &center, float zLayer = 0) override;
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
        /// <param name="zLayer">The zlayer of the bitmap</param>
        virtual void FillEllipse(const Core::Vector2 &position, const Core::Size2F size, const Color &color, float rotation, const Vector2 &center, float ZLayer = 0) override;
        /// <summary>
        /// Draws a rectangle
        /// </summary>
        /// <param name="rectangle">The rectangle to draw</param>
        /// <param name="color">The color of the rectangle</param>
        /// <param name="rotation">The rotation of the Rectangle</param>
        /// <param name="center">The center of the Rectangle</param>
        /// <param name="zLayer">The zlayer of the bitmap</param>
        virtual void FillRectangle(const Core::RectangleF &rectangle, const Color &color, float rotation, const Vector2 &center, float zLayer = 0) override;

        virtual void DrawString(const std::string &text, const TextFormat &font, const Core::RectangleF &bounds, const Vector2 &position, const Color &color, float rotation, float zLayer = 0) override;

//////////////////////////////////////////////////////////////
//Constructors
//////////////////////////////////////////////////////////////
      public:
        DirectXGraphicsEngine(Core::GameWindow &gameWindow);
        ~DirectXGraphicsEngine();
      };
    }
  }
}
