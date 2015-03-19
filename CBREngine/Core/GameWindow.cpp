#pragma
#include <Windows.h>
#include "GameWindow.h"


namespace CBREngine
{
  namespace Core
  {
    static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
      HDC deviceContext;
      PAINTSTRUCT paintStructure;

      switch (msg)
      {
        case WM_PAINT:
          deviceContext = BeginPaint(hWnd, &paintStructure);
          // TODO: Add any drawing code here...
          EndPaint(hWnd, &paintStructure);
          break;

        case WM_DESTROY:
          PostQuitMessage(0);
          break;
          
        default:
          return DefWindowProc(hWnd, msg, wParam, lParam);
      }
      return 0;
    }

    void GameWindow::RegisterWindow()
    {
      WNDCLASS wClass;

      wClass.style = CS_HREDRAW | CS_VREDRAW;
      wClass.lpfnWndProc = WndProc;
      wClass.cbClsExtra = NULL;
      wClass.cbWndExtra = NULL;
      wClass.hInstance = Instance;
      wClass.hIcon = NULL;
      wClass.hCursor = LoadCursor(NULL, IDC_ARROW);
      wClass.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
      wClass.lpszMenuName = NULL;
      wClass.lpszClassName = Name;

      RegisterClass(&wClass);
    }

    void GameWindow::UnregisterWindow()
    {
      UnregisterClass(Name, Instance);
    }

    void GameWindow::Show(int nShowCmd)
    {
      ShowWindow(Handle, nShowCmd);
      UpdateWindow(Handle);
    }

    GameWindow::GameWindow(HINSTANCE instance, char *name, int width, int height)
    {
      Name = new char[std::strlen(name)];
      std::strcpy(Name, name);
      Instance = instance;

      RegisterWindow();

      Handle = CreateWindow(name, name, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, 0, width, height, NULL, NULL, Instance, NULL);

      if (!Handle)
        throw new std::exception("Failed to create Window");
    }

    GameWindow::~GameWindow()
    {
      UnregisterWindow();
      delete[] Name;
    }
  }
}
