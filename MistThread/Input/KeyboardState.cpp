#include "KeyboardState.h"


namespace MistThread
{
  namespace Input
  {

    unsigned char AsciiLookup[KEYBOARD_ARR_SIZE];


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


    std::vector<Key> KeyboardState::GetAllKeysDown() const
    {
      //The list of keys down
      std::vector<Key> kDwn;

      //Populate a list of them via loop and casting.
      for (int i = 0; i < KEYBOARD_ARR_SIZE; ++i)
        if (KeysDown[i])
          kDwn.push_back(static_cast<Key>(i));

      //Return with copy ctor call. Should be cheap.
      return kDwn;
    }


    KeyboardState::KeyboardState()
    {

    }

    KeyboardState::~KeyboardState()
    {

    }
  }
}
