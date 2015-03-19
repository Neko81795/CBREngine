#include "GraphicsEngineCore.h"
#include "DirectXGraphicsEngine.h"
#include "../Color.h"


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

      }

      void DirectXGraphicsEngine::Clear(const Color &color)
      {
        pDeviceContext->ClearRenderTargetView(pRenderTargetView, color.ToRGBA());
      }

      void DirectXGraphicsEngine::EndDraw()
      {
        
        pSwapChain->Present(1, 0); //present next vBlank, discard previously queued now
      }

      HRESULT DirectXGraphicsEngine::CreateDeviceSwapChainBackBufferAndRenderTargetView(const Core::GameWindow &gameWindow, int width, int height)
      {
        HRESULT hr;
        DXGI_MODE_DESC bufferDescription;

        bufferDescription.Width = width;
        bufferDescription.Height = height;
        bufferDescription.RefreshRate.Numerator = 60;
        bufferDescription.RefreshRate.Denominator = 1;
        bufferDescription.Format = DXGI_FORMAT_R8G8B8A8_UNORM; //32bit(RGBA), unsigned, normalized
        bufferDescription.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;//double buffer don't care
        bufferDescription.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

        DXGI_SWAP_CHAIN_DESC swapChainDescription;

        swapChainDescription.BufferDesc = bufferDescription;
        swapChainDescription.SampleDesc.Count = 1;  // anti aliasing multi-sampling
        swapChainDescription.SampleDesc.Quality = 0;// anti aliasing multi-sampling
        swapChainDescription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
        swapChainDescription.BufferCount = 2;
        swapChainDescription.OutputWindow = gameWindow.Handle;
        swapChainDescription.Windowed = true;
        swapChainDescription.SwapEffect = DXGI_SWAP_EFFECT_DISCARD; //we don't care about it anymore. let the graphics decide
        swapChainDescription.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

        // This array defines the ordering of feature levels that D3D should attempt to create.
        D3D_FEATURE_LEVEL featureLevels[] =
        {
          D3D_FEATURE_LEVEL_11_1,
          D3D_FEATURE_LEVEL_11_0,
          D3D_FEATURE_LEVEL_10_1,
          D3D_FEATURE_LEVEL_10_0,
          D3D_FEATURE_LEVEL_9_3,
          D3D_FEATURE_LEVEL_9_1
        };

        if (FAILED(hr = D3D11CreateDeviceAndSwapChain(
          NULL, // use default adapter
          D3D_DRIVER_TYPE_HARDWARE,
          NULL,// Software (not needed by hardware driver)
          0,// flags
          featureLevels,
          ARRAYSIZE(featureLevels),
          D3D11_SDK_VERSION,
          &swapChainDescription,
          &pSwapChain,
          &pDevice,
          NULL, //? Feature Level
          &pDeviceContext)))
          return hr;

        if (FAILED(hr = pSwapChain->GetBuffer(0, __uuidof(ID3D11Texture2D), (void**)&pBackBuffer)))
          return hr;

        if (FAILED(hr = pDevice->CreateRenderTargetView(pBackBuffer, NULL /*Render target view description*/, &pRenderTargetView)))
          return hr;

        return hr;
      }

      DirectXGraphicsEngine::DirectXGraphicsEngine(const Core::GameWindow &gameWindow, int width, int height)
      {
        
        if(FAILED(CreateDeviceSwapChainBackBufferAndRenderTargetView(gameWindow, width, height)))
          throw std::exception("Failed to initialize DirectX");//TODO add why we failed

        pDeviceContext->OMSetRenderTargets(1, &pRenderTargetView, NULL /*depth stencil view*/);

      }

      DirectXGraphicsEngine::~DirectXGraphicsEngine()
      {
        pDevice->Release();
        pDeviceContext->Release();
        pSwapChain->Release();
        pRenderTargetView->Release();
        pBackBuffer->Release();
        pVertexBuffer->Release();
        pVS->Release();
        pPS->Release();
        pVS_Buffer->Release();
        pPS_Buffer->Release();
        pVertexLayout->Release();

        delete pDevice;
        delete pDeviceContext;
        delete pSwapChain;
        delete pRenderTargetView;
        delete pBackBuffer;
        delete pVertexBuffer;
        delete pVS;
        delete pPS;
        delete pVS_Buffer;
        delete pPS_Buffer;
        delete pVertexLayout;
      }
    }
  }
}
