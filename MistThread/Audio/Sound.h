#pragma once

#include "fmod.hpp"
#include <string>

namespace MistThread
{
  namespace Audio
  {
    class Sound
    {
    public:
      
      Sound();
      ~Sound();

      void Load(std::string localPath);
      Sound& Stream(std::string localPath);
      Sound& Play(std::string localPath);

      void Stop();
      void TogglePaused();

      float GetVolume();
      bool GetMute();
      void GetPaused();

      void SetMute(bool isMuted);
      void SetVolume(float); //0.0 - 1.0
      void SetPaused();
      
      //-- GetWaveData( ??? )
      //-- GetSpectrumData( ??? 

    private:
      FMOD::Channel *channel;

    };
  }
}

