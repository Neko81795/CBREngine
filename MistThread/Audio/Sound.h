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

      void Load(const std::string &localPath);
      Sound& Stream(const std::string &localPath);
      Sound& Play(const std::string &localPath);

      void Stop();
      void TogglePaused();
      void ToggleMute();

      float GetVolume();
      bool GetMute();
      bool GetPaused();

      void SetMute(bool isMuted);
      void SetVolume(float newVolume); //0.0 - 1.0
      void SetPaused(bool isPaused);
      
      //-- GetWaveData( ??? )
      //-- GetSpectrumData( ??? 

    private:
      FMOD::Channel *channel;

    };
  }
}

