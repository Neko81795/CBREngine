#include "GraphicsEngineCore.h"
#include "DirectXGraphicsEngine.h"
#include "../../Core/Game.h"
#include "../../Core/GameWindow.h"
#include "../Color.h"
#include "../Bitmap.h"
#include <d2d1helper.h>


namespace MistThread
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

        GraphicsEvent evnt(*this);
        DeviceRecreated(evnt);
      }

      void DirectXGraphicsEngine::CreateDeviceIndependentResources()
      {
        CoCreateInstance(CLSID_WICImagingFactory, NULL, CLSCTX_INPROC_SERVER, __uuidof(IWICImagingFactory),
                         reinterpret_cast<void **>(ImageFactory.GetAddressOf()));

        DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, __uuidof(TextFactory), reinterpret_cast<IUnknown**>(TextFactory.GetAddressOf()));
      }

      void DirectXGraphicsEngine::WindowResized(Core::WindowEvent & evnt)
      {
        while(Lock.test_and_set());
        if(RenderTarget)
        {
          Size2 size = evnt.Window.GetClientSize();
          if(RenderTarget->Resize(D2D1_SIZE_U{static_cast<UINT32>(size.Width), static_cast<UINT32>(size.Height)}) != S_OK)
          {
            RenderTarget.Reset();
          }
        }
        Lock.clear();
      }

      void DirectXGraphicsEngine::DisplayChanged(Core::WindowEvent & evnt)
      {
        while(Lock.test_and_set());
        evnt.Window.Invalidate();
        Lock.clear();
      }

      void DirectXGraphicsEngine::LoadBitmapFromFile(const std::string & path, Bitmap & bitmap)
      {
        ComPtr<IWICBitmapDecoder> decoder;
        HRESULT hr;

        std::wstring d(path.begin(), path.end());

        if(FAILED((hr = ImageFactory->CreateDecoderFromFilename(reinterpret_cast<LPCWSTR>(d.c_str()), NULL, GENERIC_READ,
                                                                WICDecodeMetadataCacheOnLoad, decoder.GetAddressOf()))))
          throw std::exception("Failed to load Bitmap: ");

        ComPtr<IWICBitmapFrameDecode> frame;
        if(FAILED(decoder->GetFrame(0, frame.GetAddressOf())))
          throw std::exception("Failed to load Bitmap");


        if(FAILED(ImageFactory->CreateFormatConverter(bitmap.WICImage.GetAddressOf())))
          throw std::exception("Failed to load Bitmap");

        if(FAILED(bitmap.WICImage->Initialize(frame.Get(), GUID_WICPixelFormat32bppPBGRA,
                                              WICBitmapDitherTypeNone, NULL, 0.0, WICBitmapPaletteTypeCustom)))
          throw std::exception("Failed to load Bitmap");
      }

      void DirectXGraphicsEngine::ReloadBitmap(Bitmap & bitmap)
      {
        if(FAILED(RenderTarget->CreateBitmapFromWicBitmap(bitmap.WICImage.Get(), bitmap.D2DImage.ReleaseAndGetAddressOf())))
          throw std::exception("Failed to load Bitmap");
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
        D2D1_SIZE_F size = RenderTarget->GetSize();
        return Vector2(size.width / 2, size.height / 2);
      }

      Size2 DirectXGraphicsEngine::GetWindowBounds() const
      {
        D2D1_SIZE_F size = RenderTarget->GetSize();
        return Size2(static_cast<int>(size.width), static_cast<int>(size.height));
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
        while(Lock.test_and_set());
        if(!RenderTarget)
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
        if(RenderTarget->EndDraw() == D2DERR_RECREATE_TARGET)
          RenderTarget.Reset();
        Lock.clear();
        //pSwapChain->Present(1, 0); //present next vBlank, discard previously queued now
      }

      void DirectXGraphicsEngine::DrawRectangle(const Core::RectangleF &rectangle, const Color &color, float stroke, float rotation, const Vector2 &center, float zLayer)
      {
        Vector2 windowCenter = GetWindowCenter();
        if(ZLayeringAffectsScale && zLayer >= CameraZ)
          return;
        float scale = 1;
        if(ZLayeringAffectsScale)
          scale = 1 / (-(zLayer - CameraZ) / 30);
        RenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(-center.X, -center.Y) *
                                   D2D1::Matrix3x2F::Scale(scale, scale) *
                                   D2D1::Matrix3x2F::Rotation(rotation) *
                                   D2D1::Matrix3x2F::Translation(((rectangle.X - (CameraPos.X * 32)) * scale) + windowCenter.X, ((rectangle.Y - (CameraPos.Y * 32)) * scale) + windowCenter.Y));

        SolidBrush->SetColor(color);
        RenderTarget->DrawRectangle(D2D1::RectF(0, 0, rectangle.Width, rectangle.Height), SolidBrush.Get(), stroke);
      }

      void DirectXGraphicsEngine::DrawEllipse(const Core::Vector2 & position, const Core::Size2F size, const Color & color, float stroke, float rotation, const Vector2 & center, float zLayer)
      {
        Vector2 windowCenter = GetWindowCenter();
        if(ZLayeringAffectsScale && zLayer >= CameraZ)
          return;
        float scale = 1;
        if(ZLayeringAffectsScale)
          scale = 1 / (-(zLayer - CameraZ) / 30);
        RenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(-center.X, -center.Y) *
                                   D2D1::Matrix3x2F::Scale(scale, scale) *
                                   D2D1::Matrix3x2F::Rotation(rotation) *
                                   D2D1::Matrix3x2F::Translation(((position.X - (CameraPos.X * 32)) * scale) + windowCenter.X, ((position.Y - (CameraPos.Y * 32)) * scale) + windowCenter.Y));

        SolidBrush->SetColor(color);
        RenderTarget->DrawEllipse(D2D1::Ellipse(D2D1::Point2F(center.X, center.Y), size.Width / 2, size.Height / 2), SolidBrush.Get(), stroke);
      }

      void DirectXGraphicsEngine::DrawBitmap(const Bitmap &image, const Vector2 &position, float opacity, const Vector2 &center, float rotation, const Core::Size2F &scale, const Core::RectangleF * source, float zLayer)
      {
        Vector2 windowCenter = GetWindowCenter();
        if(ZLayeringAffectsScale && zLayer >= CameraZ)
          return;
        float addscale = 1;
        if(ZLayeringAffectsScale)
          addscale = 1 / (-(zLayer - CameraZ) / 30);
        RenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(-center.X, -center.Y) *
                                   D2D1::Matrix3x2F::Scale(scale.Width * addscale, scale.Height * addscale) *
                                   D2D1::Matrix3x2F::Rotation(rotation) *
                                   D2D1::Matrix3x2F::Translation(((position.X - (CameraPos.X * 32)) * addscale) + windowCenter.X, ((position.Y - (CameraPos.Y * 32)) * addscale) + windowCenter.Y));


        if(source == NULL)
        {
          RenderTarget->DrawBitmap(image.D2DImage.Get(), NULL, opacity, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, NULL);
        }
        else
        {
          D2D1_RECT_F rect = D2D1::RectF(source->GetLeft(), source->GetTop(), source->GetRight(), source->GetBottom());
          RenderTarget->DrawBitmap(image.D2DImage.Get(), NULL, opacity, D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR, &rect);
        }
      }

      void DirectXGraphicsEngine::FillEllipse(const Core::Vector2 & position, const Core::Size2F size, const Color & color, float rotation, const Vector2 & center, float zLayer)
      {
        Vector2 windowCenter = GetWindowCenter();
        if(ZLayeringAffectsScale && zLayer >= CameraZ)
          return;
        float scale = 1;
        if(ZLayeringAffectsScale)
          scale = 1 / (-(zLayer - CameraZ) / 30);
        RenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(-center.X, -center.Y) *
                                   D2D1::Matrix3x2F::Scale(scale, scale) *
                                   D2D1::Matrix3x2F::Rotation(rotation) *
                                   D2D1::Matrix3x2F::Translation(((position.X - (CameraPos.X * 32)) * scale) + windowCenter.X, ((position.Y - (CameraPos.Y * 32)) * scale) + windowCenter.Y));

        SolidBrush->SetColor(color);
        RenderTarget->FillEllipse(D2D1::Ellipse(D2D1::Point2F(center.X, center.Y), size.Width / 2, size.Height / 2), SolidBrush.Get());
      }

      void DirectXGraphicsEngine::FillRectangle(const Core::RectangleF &rectangle, const Color &color, float rotation, const Vector2 &center, float zLayer)
      {
        Vector2 windowCenter = GetWindowCenter();
        if(ZLayeringAffectsScale && zLayer >= CameraZ)
          return;
        float scale = 1;
        if(ZLayeringAffectsScale)
          scale = 1 / (-(zLayer - CameraZ) / 30);
        RenderTarget->SetTransform(D2D1::Matrix3x2F::Translation(-center.X, -center.Y) *
                                   D2D1::Matrix3x2F::Scale(scale, scale) *
                                   D2D1::Matrix3x2F::Rotation(rotation) *
                                   D2D1::Matrix3x2F::Translation(((rectangle.X - (CameraPos.X * 32)) * scale) + windowCenter.X, ((rectangle.Y - (CameraPos.Y * 32)) * scale) + windowCenter.Y));

        SolidBrush->SetColor(color);
        RenderTarget->FillRectangle(D2D1::RectF(0, 0, rectangle.Width, rectangle.Height), SolidBrush.Get());
      }

      void Engines::DirectXGraphicsEngine::DrawString()
      {}



      DirectXGraphicsEngine::DirectXGraphicsEngine(Core::GameWindow &window)
      {
        window.OnResize += Core::Delegate<Core::WindowEvent &>([](void * obj, Core::WindowEvent &evnt)
        {
          static_cast<DirectXGraphicsEngine*>(obj)->WindowResized(evnt);
        }, this);
        window.OnDisplayChange += Core::Delegate<Core::WindowEvent &>([](void * obj, Core::WindowEvent &evnt)
        {
          static_cast<DirectXGraphicsEngine*>(obj)->DisplayChanged(evnt);
        }, this);

        D2D1_FACTORY_OPTIONS fo = {};

#ifdef _DEBUG
        fo.debugLevel = D2D1_DEBUG_LEVEL_INFORMATION;
#endif
        //TODO add why we failed
        if(FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_MULTI_THREADED, fo, Factory.GetAddressOf())))
          throw std::exception("Failed to create D2D");

        if(FAILED(CoInitialize(NULL)))
          throw std::exception("Failed to create D2D");

        CreateDeviceIndependentResources();
      }

      DirectXGraphicsEngine::~DirectXGraphicsEngine()
      {
        ImageFactory.Reset();
        CoUninitialize();
      }
    }
  }
}
