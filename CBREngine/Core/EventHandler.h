#pragma once
#include "Delegate.h"
#include "Event.h"
#include <list>

namespace CBREngine
{
  namespace Core
  {
    template <typename T1 = Event&, typename T2 = Delegate<T1>>
    class EventHandler
    {
    private:
      std::list<T2> ls;
    public:
      EventHandler<T1, T2> &operator+=(T2 del)
      {
        ls.push_back(del);
        return *this;
      }
      EventHandler<T1, T2> &operator-=(T2 del)
      {
        ls.remove(del);
        return *this;
      }
      void operator()(T1 evnt)
      {
        for each (T2 func in ls)
        {
          func(evnt);
        }
      }
      virtual ~EventHandler() {}
    };
  }
}

