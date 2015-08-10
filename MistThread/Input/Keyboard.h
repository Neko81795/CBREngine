#pragma once
#include "KeyboardState.h"
#include "KeyCombo.h"


namespace MistThread
{
  namespace Input
  {
    namespace Engines
    {
      class DirectXInputEngine; //forward declaration
    }
    class Keyboard
    {
      friend Engines::DirectXInputEngine;
    private:
      static KeyboardState Last_;
      static KeyboardState Current_;
      static KeyCombo CurrentCombo_;
    public:
      /// <summary>
      /// returns if the key was pressed this loop
      /// </summary>
      /// <param name="key">the key to check</param>
      static bool isKeyPressed(Key key);
      /// <summary>
      /// returns a read-only copy of the last keyboard state
      /// </summary>
      static const KeyboardState &Last;
      /// <summary>
      /// returns a read-only copy of the current keyboard state
      /// </summary>
      static const KeyboardState &Current;
      /// <summary>
      /// returns a read-only copy of the current keyboard user combo
      /// </summary>
      static const KeyCombo &CurrentCombo;
      /// <summary>
      /// the time in milliseconds from the last key pressed before the key combo is cleared
      /// </summary>
      static int KeyCoolDown;
      /// <summary>
      /// the max number of keys to track in the combo
      /// </summary>
      static int maxKeyComboLength;
    };
  }
}

