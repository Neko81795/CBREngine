#include "GameTime.h"
namespace CBREngine
{
  namespace Core
  {
    GameTime::GameTime() : ElapsedTime(_ElapsedTime), TotalTime(_TotalTime), FramesPerSecond(_FramesPerSecond)
    {
      _Frames = 0;
      _FpsTime = 0;
      _StartTime = (static_cast<double>(clock()) / CLOCKS_PER_SEC);
      _LastTime = (static_cast<double>(clock()) / CLOCKS_PER_SEC);
      _ElapsedTime = 0;
      _TotalTime = 0;
      _FramesPerSecond = 0;
    }

    GameTime & GameTime::operator=(const GameTime & gt)
    {
      _Frames = gt._Frames;
      _FpsTime = gt._FpsTime;
      _StartTime = gt._StartTime;
      _LastTime = gt._LastTime;
      _ElapsedTime = gt.ElapsedTime;
      _TotalTime = gt.TotalTime;
      _FramesPerSecond = gt.FramesPerSecond;

      return *this;
    }

    double GameTime::GetActualElapsedTime() const
    {
      return (static_cast<double>(clock()) / CLOCKS_PER_SEC) - _LastTime;
    }

    void GameTime::Tick()
    {

      double t = (static_cast<double>(clock()) / CLOCKS_PER_SEC);
      _ElapsedTime = t - _LastTime;
      _TotalTime = t - _StartTime;
      _LastTime = t;
      _FpsTime += _ElapsedTime;
      ++_Frames;
      if (_FpsTime >= 0.5)
      {
        _FramesPerSecond = (_Frames / ((_FpsTime / 0.5))) / 0.5;
        _Frames = 0;
        _FpsTime = 0;
      }
    }
  }
}
