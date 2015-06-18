#pragma once

#include "AudioEngineCore.h"

#include <map>
#include <list>
#include <string>

#include <fmod.hpp>

namespace MistThread
{
  namespace Audio
  {
    namespace Engines
    {
      class FMODAudioEngine : public AudioEngineCore
      {
      public:
        FMODAudioEngine();
        ~FMODAudioEngine();

        void LoadFile(const std::string &soundToAdd);
        void Stream(const std::string &toStream, FMOD::Channel **channel);
        void Bind(const std::string &soundToBind, FMOD::Channel **channel);
      private:
        std::map<std::string, FMOD::Sound *> LoadedSounds;
        std::map<std::string, std::list<FMOD::Sound>> SoundGroups;


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
