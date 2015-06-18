#pragma once
#include <vector>

#include "InputEngineCore.h"
#include "../KeyboardEvent.h"
#include "../KeyEventInfo.h"

namespace MistThread
{
  namespace Core
  {
    class GameWindow; //forward declaration
  }
  namespace Input
  {
    namespace Engines
    {
      class DirectXInputEngine : public InputEngineCore
      {
      private:
        std::vector<KeyEventInfo> Queue;
      public:
        void KeyDown(KeyboardEvent &evnt);
        void KeyUp(KeyboardEvent &evnt);
        void Update(Core::GameTime gameTime) override;
        DirectXInputEngine(Core::GameWindow& gameWindow);
        ~DirectXInputEngine();
      };
    }
  }
}

