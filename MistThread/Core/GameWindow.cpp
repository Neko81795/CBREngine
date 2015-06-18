#pragma
#include <Windows.h>
#include "GameWindow.h"
#include "Size2.h"


namespace MistThread
{
  namespace Core
  {
    LRESULT GameWindow::Paint(UINT, WPARAM, LPARAM, BOOL &)
    {
      PAINTSTRUCT ps;

      BeginPaint(&ps);

      EndPaint(&ps);

      return 0;
    }

    LRESULT GameWindow::Destroy(UINT, WPARAM, LPARAM, BOOL &)
    {
      PostQuitMessage(0);
      return 0;
    }

    LRESULT GameWindow::Resize(UINT, WPARAM, LPARAM, BOOL &)
    {
      RECT rect = {};
      GetClientRect(&rect);
      if (rect.bottom <= 10)
      {
        ResizeClient(rect.right, 10);
      }
      WindowEvent evnt(*this);
      OnResize(evnt);
      return 0;
    }

    LRESULT GameWindow::DisplayChange(UINT, WPARAM, LPARAM, BOOL &)
    {
      WindowEvent evnt(*this);
      OnDisplayChange(evnt);
      return 0;
    }

    LRESULT GameWindow::KeyDown(UINT, WPARAM, LPARAM, BOOL &)
    {

    }

    LRESULT GameWindow::KeyUp(UINT, WPARAM, LPARAM, BOOL &)
    {

    }

    Size2 GameWindow::GetClientSize()
    {
      RECT rect = {};
      GetClientRect(&rect);
      return Size2(static_cast<int>(rect.right), static_cast<int>(rect.bottom));
    }

    GameWindow::GameWindow(char * name)
    {
      Handle = Create(NULL, 0, name);
    }
  }
}
