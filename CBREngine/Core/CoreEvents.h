#pragma once
#include "Event.h"

namespace CBREngine
{
  namespace Core
  {
    class GameWindow;

    class WindowEvent : public Event
    {
    private:
      void operator=(WindowEvent &) {}
    public:
      GameWindow &Window;
      WindowEvent(GameWindow & window) : Window(window) {}
    };
  }
}

