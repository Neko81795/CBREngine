#include "KeyboardState.h"


namespace MistThread
{
  namespace Input
  {
    bool KeyboardState::IsKeyDown(Key key) const
    {
      return KeysDown[key];
    }

    void KeyboardState::SetKeyDown(Key key, bool pressed)
    {
      if(key == Key::NONE)
        return;
      KeysDown[key] = pressed;
    }

    KeyboardState::KeyboardState()
    {

    }

    KeyboardState::~KeyboardState()
    {

    }
  }
}
