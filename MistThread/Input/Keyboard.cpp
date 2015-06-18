#include "Keyboard.h"


namespace MistThread
{
  namespace Input
  {
    KeyboardState Keyboard::Last;
    KeyboardState Keyboard::Current;
    KeyCombo Keyboard::CurrentCombo;

    int Keyboard::KeyCoolDown = 500;
    int Keyboard::maxKeyComboLength = 25;

    bool Keyboard::isKeyPressed(Key key)
    {
      return Current.IsKeyDown(key) && !Last.IsKeyDown(key);
    }

    const KeyboardState &Keyboard::GetLast()
    {
      return Last;
    }

    const KeyboardState &Keyboard::GetCurrent()
    {
      return Current;
    }

    const KeyCombo &Keyboard::GetCombo()
    {
      return CurrentCombo;
    }
  }
}
