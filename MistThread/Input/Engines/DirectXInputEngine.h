#pragma once
#include "InputEngineCore.h"

namespace MistThread
{
  namespace Input
  {
    namespace Engines
    {
      class DirectXInputEngine : public InputEngineCore
      {
      public:
        void Update(Core::GameTime gameTime) override;
        DirectXInputEngine();
        ~DirectXInputEngine();
      };
    }
  }
}

