#pragma once
#include "../../Core/GameTime.h"

#define __ABSTRACT = 0

namespace MistThread
{
  namespace Input
  {
    namespace Engines
    {
      class InputEngineCore
      {
      public:
        virtual void Update(Core::GameTime gameTime) __ABSTRACT;
        virtual ~InputEngineCore() {}
      };
    }
  }
}

