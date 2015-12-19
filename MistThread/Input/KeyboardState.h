#pragma once
#include "Key.h"
#include <vector>
#define KEYBOARD_ARR_SIZE 256



namespace MistThread
{
  namespace Input
  {
    struct KeyboardState
    {
    private:
      bool KeysDown[KEYBOARD_ARR_SIZE];
    public:
      bool IsKeyDown(Key key) const;
      void SetKeyDown(Key key, bool pressed);
      std::vector<Key> GetAllKeysDown() const;

      KeyboardState();
      ~KeyboardState();
    };
  }
}

