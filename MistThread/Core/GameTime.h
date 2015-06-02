#pragma once
#include <time.h>

namespace MistThread
{
  namespace Core
  {
    class GameTime
    {
      ///////////////////////////////
      //Variables
      ///////////////////////////////
    private:
      int _Frames;
      double _FpsTime;
      double _StartTime;
      double _LastTime;
      double _ElapsedTime;
      double _TotalTime;
      double _FramesPerSecond;
    public:
      /// <summary>
      /// Returns the number of seconds the last tick took to complete
      /// </summary>
      const double &ElapsedTime;
      /// <summary>
      /// Returns the number of seconds since the game started
      /// </summary>
      const double &TotalTime;
      /// <summary>
      /// Returns the Frames per second the game averaged over the last 10 ticks
      /// </summary>
      const double &FramesPerSecond;


      ///////////////////////////////
      //Methods
      ///////////////////////////////
    private:
      /// <summary>
      /// Returns the number of milliseconds from the start of the last tick till now
      /// </summary>
      double GetActualElapsedTime() const;
    public:
      void Tick();

      GameTime &operator=(const GameTime & gt);

      GameTime();
    };
  }
}

