#pragma
#include <Windows.h>
#include "GameWindow.h"
#include "Size2.h"


namespace MistThread
{
  namespace Core
  {
    Input::Key GameWindow::HandleKeyPress(WPARAM key, LPARAM lParam)
    {
      bool isRightKey = (lParam & 0x01000000) != 0;//gets the "extended" info

      switch (key)
      {
      case VK_SHIFT:
        return isRightKey ? Input::RShift : Input::LShift;
      case VK_CONTROL:
        return isRightKey ? Input::RControl : Input::LControl;
      case VK_MENU:
        return isRightKey ? Input::RAlt : Input::LAlt;
      }

      return static_cast<Input::Key>(key);
    }

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
      if(rect.bottom <= 10)
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

    LRESULT GameWindow::KeyDown(UINT, WPARAM key, LPARAM lParam, BOOL &)
    {
      if (lParam & 0x40000000)
        return DefWindowProc(); //ignore repeats

      Input::KeyboardEvent evnt(HandleKeyPress(key, lParam), true);
      OnKeyDown(evnt);
      return 0;
    }

    LRESULT GameWindow::KeyUp(UINT, WPARAM key, LPARAM lParam, BOOL &)
    {
      Input::KeyboardEvent evnt(HandleKeyPress(key, lParam), false);
      OnKeyUp(evnt);
      return 0;
    }

    LRESULT GameWindow::SysKeyDown(UINT msg, WPARAM key, LPARAM lParam, BOOL &)
    {
      if (lParam & 0x40000000 || !(lParam & (1 << 29)))
        return DefWindowProc(); //ignore repeats and messages from global space

      Input::KeyboardEvent evnt(HandleKeyPress(key, lParam), true);
      OnKeyDown(evnt);
      return DefWindowProc();
    }

    LRESULT GameWindow::SysKeyUp(UINT, WPARAM key, LPARAM lParam, BOOL &)
    {
      if (!(lParam & (1 << 29)))
        return DefWindowProc(); //ignore messages from global space

      Input::KeyboardEvent evnt(HandleKeyPress(key, lParam), false);
      OnKeyUp(evnt);
      return DefWindowProc();
    }

    LRESULT GameWindow::MouseMove(UINT, WPARAM flag, LPARAM position, BOOL &)
    {
      Vector2 pos(static_cast<float>(GET_X_LPARAM(position)),
                  static_cast<float>(GET_Y_LPARAM(position)));

      Input::MouseEvent evnt(pos,
                             (flag & MK_LBUTTON) != 0,
                             (flag & MK_MBUTTON) != 0,
                             (flag & MK_RBUTTON) != 0,
                             (flag & MK_CONTROL) != 0,
                             (flag & MK_SHIFT) != 0,
                             (flag & MK_ALT) != 0);

      OnMouseMove(evnt);
      return 0;
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
