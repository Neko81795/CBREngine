#include "KeyCombo.h"


namespace MistThread
{
  namespace Input
  {
    bool KeyCombo::Contains(const KeyCombo & other) const
    {
      //the other is bigger, there is no way that this contains all of that
      //or the other is empty
      if(other.Keys.size() > Keys.size() || other.Keys.size() == 0)
        return false;

      for(int start = 0; start <= Keys.size() - other.Keys.size(); start++)
      {
        if(Keys.size() - start < other.Keys.size())
          return false;

        if(other.Keys[0].Key == Keys[start].Key)
        {
          bool worked = true;
          for(int i = 0; i < other.Keys.size(); i++)
          {
            if(other.Keys[i].Key != Keys[start + i].Key)
            {
              worked = false;
              break;
            }
          }
          if(worked)
            return true;
        }
      }
      return false;
    }

    KeyCombo::KeyCombo(std::vector<KeyEventInfo> keys)
    {
      Keys = keys;
    }

    KeyCombo::KeyCombo(std::vector<Key> keys)
    {
      for(int i = 0; i < keys.size(); i++)
      {
        Keys.push_back(keys[i]);
      }
    }

    KeyCombo::KeyCombo()
    {}
    KeyCombo::~KeyCombo()
    {}

    const KeyCombo KeyCombo::Konami(std::vector<Key>{Key::Up, Key::Up, Key::Down, Key::Down, Key::Left, Key::Right, Key::Left, Key::Right, Key::B, Key::A, Key::Enter});
  }
}
