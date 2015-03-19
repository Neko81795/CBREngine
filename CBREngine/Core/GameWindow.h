#pragma once
#include <Windows.h>
#include <string>

namespace CBREngine
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
    class GameWindow
    {
      //variables
    private:
      HWND Handle;
      HINSTANCE Instance;
      char *Name;
      friend class Graphics::Engines::DirectXGraphicsEngine;

      //methods
    private:
      /// <summary>
      /// Creates and registers a new window class
      /// </summary>
      /// <param name="name">the handle of the window</param>
      /// <param name="instance">the message from the operating system</param>
      /// <param name="instance">a parameter</param>
      /// <param name="instance">another parameter</param>
      friend static LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

      /// <summary>
      /// Creates and registers a new window class
      /// </summary>
      void RegisterWindow();

      /// <summary>
      /// Unregisters our window
      /// </summary>
      void UnregisterWindow();
    public:
      /// <summary>
      /// Shows the Window
      /// </summary>
      /// <param name="nShowCmd">How to display the window</param>
      void Show(int nShowCmd = 1);

      /// <summary>
      /// Creates a new game window
      /// </summary>
      /// <param name="instance">the instance of the application</instance>
      /// <param name="name">the name of the window</param>
      /// <param name="width">the starting height of the window</param>
      /// <param name="height">the starting width of the window</param>
      GameWindow(HINSTANCE instance, char *name, int width = 640, int height = 480);
      
      /// <summary>
      /// Destroys the game window and all assets
      /// </summary>
      ~GameWindow();
    };
  }
}
