#pragma once

#pragma comment(lib, "d3d11.lib")

#include "GraphicsEngineCore.h"
#include <d3d11.h>



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
      class DirectXGraphicsEngine : GraphicsEngineCore
      {
      private:
        ID3D11Device *pDevice;
        ID3D11DeviceContext *pDeviceContext;
        IDXGISwapChain *pSwapChain;
        ID3D11RenderTargetView *pRenderTargetView;
        ID3D11Texture2D *pBackBuffer;
        ID3D11Buffer* pVertexBuffer;
        ID3D11VertexShader* pVS;
        ID3D11PixelShader* pPS;
        ID3D10Blob* pVS_Buffer;
        ID3D10Blob* pPS_Buffer;
        ID3D11InputLayout* pVertexLayout;
        
        HRESULT CreateDeviceSwapChainBackBufferAndRenderTargetView(const Core::GameWindow &gameWindow, int width, int height);

      protected:
        /// <summary>
        /// Sets the default font
        /// </summary>
        virtual void SetDefaultFont(char *font);
        /// <summary>
        /// Sets the default font size
        /// </summary>
        virtual void SetDefaultFontSize(double size);

      public:
        /// <summary>
        /// Gets the default font
        /// </summary>
        virtual const char *GetDefaultFont() const;
        /// <summary>
        /// Gets the default font size
        /// </summary>
        virtual double GetDefaultFontSize() const;
        /// <summary>
        /// Gets the center of the window (in pixels)
        /// </summary>
        virtual Vector2 GetWindowCenter() const;
        /// <summary>
        /// Gets the size of the window
        /// </summary>
        virtual Size2 GetWindowBounds() const;


        /// <summary>
        /// returns the size of the text the string would display
        /// </summary>
        /// <param name="text">the string</param>
        /// <param name="font">the font family</param>
        /// <param name="size">the size of the font (in point)</param>
        virtual Vector2 MeasureString(const char *text, const char *font, double size) const;

        /// <summary>
        /// toggles the full Screen mode
        /// </summary>
        virtual void ToggleFullScreen();

        /// <summary>
        /// begins the draw
        /// </summary>
        virtual void BeginDraw();

        /// <summary>
        /// clears the screen to the specified color
        /// </summary>
        virtual void Clear(const Color &color);

        /// <summary>
        /// ends the draw
        /// </summary>
        virtual void EndDraw();

        DirectXGraphicsEngine(const Core::GameWindow &gameWindow, int width = 640, int height = 480);
        ~DirectXGraphicsEngine();
      };
    }
  }
}
