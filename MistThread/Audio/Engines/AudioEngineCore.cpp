#include "AudioEngineCore.h"

#include <iostream>
#include <stdio.h>
#include "fmod_errors.h"

namespace MistThread
{
  namespace Audio
  {
    namespace Engines
    {
      AudioEngineCore::AudioEngineCore()
      {
        FMOD_RESULT result; //Temp storage for method results.

        //Create the sound system.
        result = FMOD::System_Create(&AudioSystem);
        CheckFMODResult(result);

        //Get the version of the system.
        result = AudioSystem->getVersion(&Version);
        CheckFMODResult(result);

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
        CheckFMODResult(result);

        //If we have no audio cards, no sound for us.
        if (NumDrivers == 0)
        {
          //Set our sound output to off.
          result = AudioSystem->setOutput(FMOD_OUTPUTTYPE_NOSOUND);
          CheckFMODResult(result);
        }
        else
        {
          //Get the driver capabilities.
          result = AudioSystem->getDriverCaps(0, &Capabilities, 0, &Speakermode);
          CheckFMODResult(result);

          //Set the user selected speaker mode.
          result = AudioSystem->setSpeakerMode(Speakermode);
          CheckFMODResult(result);

          if (Capabilities & FMOD_CAPS_HARDWARE_EMULATED)
          {
            //The user has the 'Acceleration' slider set to off! This is really bad
            //for latency! You might want to warn the user about this.
            //TODO: Figure out a better way to tell the user they may experience some audio issues.
            result = AudioSystem->setDSPBufferSize(1024, 10);
            CheckFMODResult(result);
            throw(std::exception("Audio acceleration not detected! Please adjust your settings and restart the application!"));
          }

          //Get the info for the sound device in place.
          result = AudioSystem->getDriverInfo(0, DriverName, 256, 0);
          CheckFMODResult(result);

          if (strstr(DriverName, "SigmaTel"))
          {
            //Sigmatel sound devices crackle for some reason if the format is PCM 16bit.
            //PCM floating point output seems to solve it.
            result = AudioSystem->setSoftwareFormat(48000, FMOD_SOUND_FORMAT_PCMFLOAT, 0, 0,
              FMOD_DSP_RESAMPLER_LINEAR);
            CheckFMODResult(result);
          }
        }

        //Figure out the speaker mode.
        result = AudioSystem->init(100, FMOD_INIT_NORMAL, 0);

        //If we were unable to create the buffer...
        if (result == FMOD_ERR_OUTPUT_CREATEBUFFER)
        {
          //Ok, the speaker mode selected isn't supported by this soundcard. Switch it back to stereo...
          result = AudioSystem->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
          CheckFMODResult(result);

          //... and re-init.
          result = AudioSystem->init(100, FMOD_INIT_NORMAL, 0);
        }

        //Regardless, check the result. If it all checks out, we're good to go!
        CheckFMODResult(result);
      }


      void AudioEngineCore::CheckFMODResult(FMOD_RESULT result)
      {
        //If we are anything other than expected...
        if (result != FMOD_OK)
          throw(std::exception(FMOD_ErrorString(result)));
      }


      AudioEngineCore::~AudioEngineCore()
      {
      }
    }
  }
}
