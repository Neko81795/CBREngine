#include "AudioEngineCore.h"

#include <iostream>
#include <string>
#include <stdio.h>
#include <map>

#include <fmod_errors.h>

namespace MistThread
{
  namespace Audio
  {
    namespace Engines
    {
      static void check(FMOD_RESULT result)
      {
        //If we are anything other than expected...
        if (result != FMOD_OK)
          throw(std::exception(FMOD_ErrorString(result)));
      }

      AudioEngineCore::AudioEngineCore()
      {
        FMOD_RESULT result; //Temp storage for method results.
        LoadedSounds = std::map<std::string, FMOD::Sound *>();

        //Create the sound system.
        result = FMOD::System_Create(&AudioSystem);
        check(result);

        //Get the version of the system.
        result = AudioSystem->getVersion(&Version);
        check(result);

        //Check out version.
        if (Version < FMOD_VERSION)
        {
          //Get the version, and inform the user accordingly that it is out of date.
          char messageBuffer[256];
          sprintf(messageBuffer, "Error! You are using an old version of FMOD %08x. This program requires %08x\n",
            Version, FMOD_VERSION);
          throw(std::exception(messageBuffer));
        }

        //Check the sound cards in the system.
        result = AudioSystem->getNumDrivers(&NumDrivers);
        check(result);

        //If we have no audio cards, no sound for us.
        if (NumDrivers == 0)
        {
          //Set our sound output to off.
          result = AudioSystem->setOutput(FMOD_OUTPUTTYPE_NOSOUND);
          check(result);
        }
        else
        {
          //Get the driver capabilities.
          result = AudioSystem->getDriverCaps(0, &Capabilities, 0, &Speakermode);
          check(result);

          //Set the user selected speaker mode.
          result = AudioSystem->setSpeakerMode(Speakermode);
          check(result);

          if (Capabilities & FMOD_CAPS_HARDWARE_EMULATED)
          {
            //The user has the 'Acceleration' slider set to off! This is really bad
            //for latency! You might want to warn the user about this.
            //TODO: Figure out a better way to tell the user they may experience some audio issues.
            result = AudioSystem->setDSPBufferSize(1024, 10);
            check(result);
            throw(std::exception("Audio acceleration not detected! Please adjust your settings and restart the application!"));
          }

          //Get the info for the sound device in place.
          result = AudioSystem->getDriverInfo(0, DriverName, 256, 0);
          check(result);

          if (strstr(DriverName, "SigmaTel"))
          {
            //Sigmatel sound devices crackle for some reason if the format is PCM 16bit.
            //PCM floating point output seems to solve it.
            result = AudioSystem->setSoftwareFormat(48000, FMOD_SOUND_FORMAT_PCMFLOAT, 0, 0,
              FMOD_DSP_RESAMPLER_LINEAR);
            check(result);
          }
        }

        //Figure out the speaker mode.
        result = AudioSystem->init(100, FMOD_INIT_NORMAL, 0);

        //If we were unable to create the buffer...
        if (result == FMOD_ERR_OUTPUT_CREATEBUFFER)
        {
          //Ok, the speaker mode selected isn't supported by this soundcard. Switch it back to stereo...
          result = AudioSystem->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
          check(result);

          //... and re-init.
          result = AudioSystem->init(100, FMOD_INIT_NORMAL, 0);
        }

        //Regardless, check the result. If it all checks out, we're good to go!
        check(result);
      }

      void AudioEngineCore::LoadFile(const std::string &soundToAdd)
      {
        //If we need to load the sound...
        if (LoadedSounds.find(soundToAdd) == LoadedSounds.end())
        {
          //...Create it and add it to the map.
          FMOD::Sound *toAdd;
          
          check(AudioSystem->createSound(soundToAdd.c_str(), FMOD_DEFAULT, 0, &toAdd));
          LoadedSounds[soundToAdd] = toAdd;
        }
      }

      void AudioEngineCore::Bind(const std::string &soundToBind, FMOD::Channel *channel)
      {
        //Bind it by playing it through a channel if applicable.
        if (LoadedSounds.find(soundToBind) != LoadedSounds.end())
          check(AudioSystem->playSound(FMOD_CHANNEL_FREE, LoadedSounds[soundToBind], false, &channel));
        else
          LoadFile(soundToBind);
      }

      void AudioEngineCore::Stream(const std::string &, FMOD::Channel *)
      {
        //TODO: REVISE STREAMING AND WHAT IT DOES.
        //FMOD::Sound *stream;
        //check(AudioSystem->createStream("C:/Users/Reverie/Source/Repos/CBREngine/EngineTest\AudioTest.ogg", FMOD_DEFAULT, 0, &stream));
        //check(AudioSystem->playSound(FMOD_CHANNEL_FREE, stream, false, &channel));
      }

      AudioEngineCore::~AudioEngineCore()
      {
      }
    }
  }
}
