#pragma once
#include <vector>
#include "Key.h"
#include "KeyEventInfo.h"

namespace MistThread
{
  namespace Input
  {
    struct KeyCombo
    {
    public:
      std::vector<KeyEventInfo> Keys;

      /// <summary>
      /// checks if this key combo contains the other
      /// </summary>
      /// <param name="other"></param>
      bool Contains(const KeyCombo &other) const;

      KeyCombo(std::vector<KeyEventInfo> keys);
      KeyCombo(std::vector<Key> keys);
      KeyCombo();
      ~KeyCombo();

      static const KeyCombo Konami;
    };
  }
}

