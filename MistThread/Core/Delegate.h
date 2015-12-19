#pragma once
namespace MistThread
{
  namespace Core
  {
    template <typename Param = Event, typename Func = void(*)(void*, Param)>
    class Delegate
    {
    private:
      void *Obj;
      Func Funct;

    public:

      void operator()(Param evnt) const
      {
        Funct(Obj, evnt);
      }

      bool operator==(const Delegate<Param>& other) const
      {
        if (Obj != other.Obj)
          return false;
        if (Funct != other.Funct)
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
          return Funct < other.Funct;

        return Obj < other.Obj;
      }


      ///////////////////////////////
      //Constructors
      ///////////////////////////////
    public:
      Delegate(Func func, void* obj)
      {
        Funct = func;
        Obj = obj;
      }
    };
  }
}
