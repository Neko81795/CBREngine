#pragma once
#include <atlbase.h>
#include <atlwin.h>
#include <string>
#include <map>

#include "CoreEventHandlers.h"
#include "../Input/InputEventHandlers.h"
#include "Size2.h"

namespace MistThread
{
  namespace Graphics
  {
    namespace Engines
    {
      class DirectXGraphicsEngine; //forward declaration
    }
  }
  namespace Core
  {
    class Game; //forward declaration

    class GameWindow
#if WIN32
      : public CWindowImpl<GameWindow, CWindow, CWinTraits<WS_OVERLAPPEDWINDOW | WS_VISIBLE>>
#endif
    {
      ////////////////////////////////// Start of class //////////////////////////////////////
      //win32 stuff
#if WIN32
      friend class Graphics::Engines::DirectXGraphicsEngine;
    public:
      DECLARE_WND_CLASS_EX("Game_Window", CS_VREDRAW | CS_HREDRAW, -1)
    private:
      BEGIN_MSG_MAP(GameWindow)
        MESSAGE_HANDLER(WM_PAINT, Paint)
        MESSAGE_HANDLER(WM_DESTROY, Destroy)
        MESSAGE_HANDLER(WM_SIZE, Resize)
        MESSAGE_HANDLER(WM_DISPLAYCHANGE, DisplayChange)
        MESSAGE_HANDLER(WM_KEYDOWN, KeyDown)
        MESSAGE_HANDLER(WM_SYSKEYDOWN, SysKeyDown)
        MESSAGE_HANDLER(WM_KEYUP, KeyUp)
        MESSAGE_HANDLER(WM_CHAR, Char)
        MESSAGE_HANDLER(WM_MOUSEMOVE, MouseMove)
      END_MSG_MAP()

      
      Input::Key HandleKeyPress(WPARAM, LPARAM);
      LRESULT Paint(UINT, WPARAM, LPARAM, BOOL &);
      LRESULT Destroy(UINT, WPARAM, LPARAM, BOOL &);
      LRESULT Resize(UINT, WPARAM, LPARAM, BOOL &);
      LRESULT DisplayChange(UINT, WPARAM, LPARAM, BOOL &);
      LRESULT KeyDown(UINT, WPARAM, LPARAM, BOOL &);
      LRESULT KeyUp(UINT, WPARAM, LPARAM, BOOL &);
      LRESULT SysKeyDown(UINT, WPARAM, LPARAM, BOOL &);
      LRESULT SysKeyUp(UINT, WPARAM, LPARAM, BOOL &);
      LRESULT Char(UINT, WPARAM, LPARAM, BOOL &);
      LRESULT MouseMove(UINT, WPARAM, LPARAM, BOOL &);
#endif
      //variables
    protected:
      HWND Handle;
    public:
      WindowEventHandler OnResize;
      WindowEventHandler OnDisplayChange;
      Input::KeyboardEventHandler OnKeyDown;
      Input::KeyboardEventHandler OnKeyUp;
      Core::EventHandler<Input::CharEvent&> OnChar;
      Input::MouseEventHandler OnMouseMove;

      //Methods
    public:
      /// <summary>
      /// Gets the size of the usable area of the window
      /// </summary>
      Size2 GetClientSize();
      /// <summary>
      /// Creates a new game window
      /// </summary>
      /// <param name="name">the name of the window</param>
      GameWindow(char *name);
    };
  }
}
