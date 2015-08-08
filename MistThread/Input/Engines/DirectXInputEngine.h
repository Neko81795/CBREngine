#pragma once
#include <vector>

#include "../../Core/Delegate.h"
#include "InputEngineCore.h"
#include "../InputEvents.h"
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
        Core::GameWindow& GameWindow;
        Core::Delegate<KeyboardEvent&> *KeyDownCallback;
        Core::Delegate<KeyboardEvent&> * KeyUpCallback;
        std::vector<KeyEventInfo> Queue;
        DirectXInputEngine &operator=(const DirectXInputEngine&) {}
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

