#include "GraphicsEngineCore.h"
#include "DirectXGraphicsEngine.h"
#include "../Color.h"
#include <d2d1helper.h>


namespace CBREngine
{
  namespace Graphics
  {
    namespace Engines
    {
      void DirectXGraphicsEngine::SetDefaultFont(char * /*font*/)
      {

      }

      void DirectXGraphicsEngine::SetDefaultFontSize(double /*size*/)
      {

      }

      void DirectXGraphicsEngine::CreateDeviceResources()
      {
        RenderTarget->CreateSolidColorBrush(D2D1::ColorF(0, 0),
                                            SolidBrush.ReleaseAndGetAddressOf());
      }

      void DirectXGraphicsEngine::CreateDeviceIndependentResources()
      {

      }

      static void WindowResized(Core::WindowEvent & evnt)
      {
        DirectXGraphicsEngine * graphics = static_cast<DirectXGraphicsEngine *>(evnt.Game->Graphics);
        if (graphics->RenderTarget)
        {
          Size2 size = evnt.Window.GetClientSize();
          if (graphics->RenderTarget->Resize(D2D1_SIZE_U{static_cast<UINT32>(size.Width), static_cast<UINT32>(size.Height)}) != S_OK)
          {
            graphics->RenderTarget.Reset();
          }
        }
      }

      static void DisplayChanged(Core::WindowEvent & evnt)
      {
        evnt.Window.Invalidate();
      }

      const char *DirectXGraphicsEngine::GetDefaultFont() const
      {
        return NULL;
      }

      double DirectXGraphicsEngine::GetDefaultFontSize() const
      {
        return 0.0;
      }

      Vector2 DirectXGraphicsEngine::GetWindowCenter() const
      {
        return Vector2();
      }

      Size2 DirectXGraphicsEngine::GetWindowBounds() const
      {
        return Size2();
      }

      Vector2 DirectXGraphicsEngine::MeasureString(const char * /*text*/, const char * /*font*/, double /*size*/) const
      {
        return Vector2();
      }

      void DirectXGraphicsEngine::ToggleFullScreen()
      {

      }

      void DirectXGraphicsEngine::BeginDraw()
      {
        if (!RenderTarget)
        {
          Size2 size = Core::Game::CurrentGame->Window->GetClientSize();
          HWND hwnd = Core::Game::CurrentGame->Window->Handle;

          Factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(),
                                          D2D1::HwndRenderTargetProperties(hwnd, D2D1_SIZE_U{static_cast<UINT32>(size.Width), static_cast<UINT32>(size.Height)}),
                                          RenderTarget.GetAddressOf());
          CreateDeviceResources();
        }
        RenderTarget->BeginDraw();
      }

      void DirectXGraphicsEngine::Clear(const Color & color)
      {
        RenderTarget->Clear(D2D1::ColorF(color.ToIntRGB(), color.A()));
      }

      void DirectXGraphicsEngine::EndDraw()
      {
        if (RenderTarget->EndDraw() == D2DERR_RECREATE_TARGET)
          RenderTarget.Reset();
        //pSwapChain->Present(1, 0); //present next vBlank, discard previously queued now
      }

      void DirectXGraphicsEngine::DrawRectangle(const Core::RectangleF &rectangle, const Color &color, float stroke, float rotation, const Vector2 &center)
      {
        SolidBrush->SetColor(color);
        RenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(-center.X, -center.Y) * D2D1::Matrix3x2F::Rotation(rotation, D2D1::Point2F(rectangle.X, rectangle.Y)));
        RenderTarget->DrawRectangle(rectangle, SolidBrush.Get(), stroke);
      }

      void DirectXGraphicsEngine::DrawEllipse(const Core::Vector2 & position, const Core::Size2F size, const Color & color, float stroke, float rotation, const Vector2 & center)
      {
        SolidBrush->SetColor(color);
        RenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(size.Width / 4 - center.X/2, size.Height / 4 - center.Y/2) * D2D1::Matrix3x2F::Rotation(rotation, D2D1::Point2F(position.X, position.Y)));
        RenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(position.X, position.Y), size.Width / 2, size.Height / 2), SolidBrush.Get(), stroke);
      }

      void DirectXGraphicsEngine::FillEllipse(const Core::Vector2 & position, const Core::Size2F size, const Color & color, float rotation, const Vector2 & center)
      {
        SolidBrush->SetColor(color);
        RenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(size.Width / 4 - center.X / 2, size.Height / 4 - center.Y / 2) * D2D1::Matrix3x2F::Rotation(rotation, D2D1::Point2F(position.X, position.Y)));
        RenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(position.X, position.Y), size.Width / 2, size.Height / 2), SolidBrush.Get());
      }

      DirectXGraphicsEngine::DirectXGraphicsEngine(Core::GameWindow &window)
      {
        window.OnResize += WindowResized;
        window.OnDisplayChange += DisplayChanged;

        D2D1_FACTORY_OPTIONS fo = {};

#ifdef DEBUG
        fo.debugLevel = D2D1_DEBUG_LEVEL_INFORMATION;
#endif
        //TODO add why we failed
        if (FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, fo, Factory.GetAddressOf())))
          throw std::exception("Failed to create D2D");
      }

      DirectXGraphicsEngine::~DirectXGraphicsEngine()
      {}
    }
  }
}
