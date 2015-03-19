#include <Windows.h>
#include "../CBREngine/Core.h"
#include "../CBREngine/Graphics.h"


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
  CBREngine::Core::GameWindow gameWindow(hInstance, "HUGHO:DSUFHKJBEGHS");

  gameWindow.Show(nShowCmd);

  CBREngine::Graphics::Engines::DirectXGraphicsEngine dxE(gameWindow);
  CBREngine::Graphics::Color clearColor(0xFF000000);

  MSG msg;
  while (1)
  {
    while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
    {
      TranslateMessage(&msg);
      DispatchMessage(&msg);
      if (msg.message == WM_QUIT)
        exit(0);
    }

    dxE.Clear(clearColor);
    dxE.EndDraw();

    clearColor.SetB(clearColor.B() + 0.001f);
  }

  return 0;
}
