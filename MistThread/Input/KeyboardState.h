#pragma once
#include "Key.h"

namespace MistThread
{
  namespace Input
  {
    struct KeyboardState
    {
    private:
      bool KeysDown[256];
    public:
      bool IsKeyDown(Key key) const;
      void SetKeyDown(Key key, bool pressed);

      KeyboardState();
      ~KeyboardState();
    };
  }
}

