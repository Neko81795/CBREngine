#include "Sound.h"
#include "../Core/Game.h"
#include "Engines/AudioEngineCore.h"

#include <fmod.hpp>
#include <fmod_errors.h>

#include <algorithm>

#define GAME_AUDIO MistThread::Core::Game::CurrentGame->Audio

namespace MistThread
{
  namespace Audio
  {
    static void check(FMOD_RESULT result)
    {
      //If we are anything other than expected...
      if (result != FMOD_OK)
        throw(std::exception(FMOD_ErrorString(result)));
    }

    Sound::Sound()
    {
      channel = 0;
    }
    Sound::~Sound()
    {
    }

    void Sound::Load(const std::string &localPath)
    {
      GAME_AUDIO->LoadFile(localPath);
      GAME_AUDIO->Bind(localPath, &channel);
    }
    Sound& Sound::Stream(const std::string &localPath)
    {
      GAME_AUDIO->Stream(localPath, &channel);
      return *this;
    }
    Sound& Sound::Play(const std::string &localPath)
    {
      FMOD_RESULT result;

      GAME_AUDIO->Bind(localPath, &channel);
      result = channel->setPaused(false);
      check(result);

      return *this;
    }

    void Sound::Stop()
    {
      FMOD_RESULT result;

      result = channel->stop();
      check(result);
    }
    void Sound::TogglePaused()
    {
      FMOD_RESULT result;
      bool isPaused;

      result = channel->getPaused(&isPaused);
      check(result);

      result = channel->setPaused(!isPaused);
      check(result);
    }
    void Sound::ToggleMute()
    {
      if (channel)
      {
        FMOD_RESULT result;
        bool isMuted;

        result = channel->getMute(&isMuted);
        check(result);

        result = channel->setMute(!isMuted);
        check(result);
      }
    }

    float Sound::GetVolume()
    {
      FMOD_RESULT result;
      float channelVolume;

      result = channel->getVolume(&channelVolume);
      check(result);

      return channelVolume;
    }
    bool Sound::GetMute()
    {
      FMOD_RESULT result;
      bool isMuted;

      result = channel->getMute(&isMuted);
      check(result);

      return isMuted;
    }
    bool Sound::GetPaused()
    {
        FMOD_RESULT result;
        bool isPaused;

        result = channel->getPaused(&isPaused);
        check(result);

        return isPaused;
    }

    void Sound::SetMute(bool isMuted)
    {
      FMOD_RESULT result;

      result = channel->setMute(isMuted);
      check(result);
    }
    void Sound::SetVolume(float newVolume)
    {
        FMOD_RESULT result;

        if (newVolume > 1)
          newVolume = 1;
        else if (newVolume < 0)
          newVolume = 0;

        result = channel->setVolume(newVolume);
        check(result);
    }
    void Sound::SetPaused(bool isPaused)
    {
        FMOD_RESULT result;

        result = channel->setPaused(isPaused);
        check(result);
    }
  }
}

#undef GAME_AUDIO
