#pragma once
#include "Delegate.h"
#include "Event.h"
#include <vector>

namespace MistThread
{
  namespace Core
  {
    template <typename T1 = Event&>
    class EventHandler
    {
    private:
      std::vector<Delegate *> ls;
    public:
      template <typename T2>
      EventHandler<T1>& operator+=(T2 del)
      {
        ls.push_back(new Delegate<T1, T2>(del));
        return *this;
      }

      template <typename T2>
      EventHandler<T1>& operator-=(T2 del)
      {
        //ls.remove(del);
        for (int i = 0; i < ls.size(); ++i)
        {
          Delegate<T1, T2>* del = dynamic_cast<Delegate<T1, T2>*>(ls[i]);
          if (!del)
            continue;

          if (del->Funct == del)
          {
            ls.erase(ls.begin() + i);
            return *this;
          }
        }

        return *this;
      }

      void operator()(T1 evnt)
      {
        for (int i = 0; i < ls.size(); ++i)
        {
          ls[i](evnt);
        }
      }

      virtual ~EventHandler()
      {
        for (int i = 0; i < ls.size(); ++i)
        {
          delete ls[i];
        }
      }
    };
  }
}

