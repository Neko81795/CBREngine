#include <Windows.h>
#include <atlbase.h>
#include <atlwin.h>
#include "../CBREngine/Core.h"
#include "../CBREngine/Graphics.h"


int WINAPI WinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nShowCmd)
{
  CBREngine::Core::GameWindow gameWindow("CBREngine Test oh boy");
  
  CBREngine::Graphics::Engines::DirectXGraphicsEngine dxE(gameWindow);
  CBREngine::Graphics::Engines::GraphicsEngineCore *graphics = &dxE;
  CBREngine::Graphics::Color clearColor(75, 120, 255);

  CBREngine::Core::Game game(&gameWindow, &dxE);

  bool run = true;

  MSG msg;
  float rot = 0;
  while (run)
  {
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
      if (msg.message == WM_QUIT)
        run = false;
    }

    dxE.BeginDraw();
    dxE.Clear(clearColor);
    dxE.DrawRectangle(CBREngine::Core::RectangleF(400, 500, 300, 500), CBREngine::Graphics::Color(0xFFFF00FF), 20, rot++, CBREngine::Core::Vector2(150, 250));
    graphics->DrawRectangle(CBREngine::Core::RectangleF(40, 40, 100, 100), CBREngine::Graphics::Color(0xFF006A6A));
    graphics->DrawEllipse(CBREngine::Core::Vector2((std::sinf(rot * 0.1f) * 400) + 600, 200), CBREngine::Core::Size2F(200, 400), CBREngine::Graphics::Color(0xFF006A6A), 30, -(rot * rot) * 0.1, CBREngine::Core::Vector2(100, 200));
    dxE.EndDraw();

    clearColor.SetB(clearColor.B() + 0.001f);
  }

  return 0;
}
