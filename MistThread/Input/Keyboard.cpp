#include "Keyboard.h"


namespace MistThread
{
  namespace Input
  {
    KeyboardState Keyboard::Last_;
    KeyboardState Keyboard::Current_;
    KeyCombo Keyboard::CurrentCombo_;

    int Keyboard::KeyCoolDown = 500;
    int Keyboard::maxKeyComboLength = 25;

    bool Keyboard::isKeyPressed(Key key)
    {
      return Current.IsKeyDown(key) && !Last.IsKeyDown(key);
    }

    const KeyboardState &Keyboard::Last = Last_;

    const KeyboardState &Keyboard::Current = Current_;

    const KeyCombo &Keyboard::CurrentCombo = CurrentCombo_;
  }
}
