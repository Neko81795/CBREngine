#pragma once
namespace MistThread
{
  namespace Core
  {
    template <typename Param = Event>
    class Delegate
    {
    private:
      void *Obj;
      void(*Func)(void*, Param);

    public:

      void operator()(Param evnt) const
      {
        Func(Obj, evnt);
      }

      bool operator==(const Delegate<Param>& other) const
      {
        if (Obj != other.Obj)
          return false;
        if (Func != other.Func)
          return false;

        return true;
      }

      bool operator!=(const Delegate<Param>& other) const
      {
        return !(*this == other);
      }

      bool operator<(const Delegate<Param>& other) const
      {
        if (Obj == other.Obj)
          return Func < other.Func;

        return Obj < other.Obj;
      }


      ///////////////////////////////
      //Constructors
      ///////////////////////////////
    public:
      Delegate(void(*func)(void *, Param), void* obj)
      {
        Func = func;
        Obj = obj;
      }
    };
  }
}
