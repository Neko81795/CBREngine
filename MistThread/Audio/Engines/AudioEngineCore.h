#pragma once

#include <string>
#include <fmod.hpp>

namespace MistThread
{
  namespace Audio
  {
    namespace Engines
    {
      class AudioEngineCore
      {
      public:
        virtual ~AudioEngineCore();

        virtual void LoadFile(const std::string &soundToAdd) = 0;
        virtual void Stream(const std::string &toStream, FMOD::Channel *channel) = 0;
        virtual void Bind(const std::string &soundToBind, FMOD::Channel *channel) = 0;
      };
    }
  }
}

