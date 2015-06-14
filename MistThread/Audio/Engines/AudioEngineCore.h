#pragma once

#include <map>
#include <list>
#include <string>

#include "fmod.hpp"

namespace MistThread
{
  namespace Audio
  {
    namespace Engines
    {
      class AudioEngineCore
      {
      public:
        AudioEngineCore();
        ~AudioEngineCore();

      private:
        static std::map<std::string, FMOD::Sound *> LoadedSounds;
        static std::map<std::string, std::list<FMOD::Sound>> SoundGroups;
        void CheckFMODResult(FMOD_RESULT result);

        FMOD::System *AudioSystem;    //Handle to the system we use to initialize and play all sounds.
        FMOD_SPEAKERMODE Speakermode; //The speaker mode- 5.1, 7.1, etc.
        FMOD_CAPS Capabilities;       //The capabilities of the soundcard.
        unsigned int Version;         //Version number.
        int NumDrivers;               //Number of drivers in the system (audio cards)
        char DriverName[256];         //The name of the driver.
      };
    }
  }
}

