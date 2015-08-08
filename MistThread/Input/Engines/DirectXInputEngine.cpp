#include "DirectXInputEngine.h"
#include "../../Core/GameWindow.h"
#include "../InputEventHandlers.h"
#include "../../Core/Game.h"
#include "../../Core/GameObjects/Space.h"
#include "../Keyboard.h"

namespace MistThread
{
  namespace Input
  {
    namespace Engines
    {
      void DirectXInputEngine::KeyDown(KeyboardEvent & evnt)
      {
        Queue.push_back(KeyEventInfo(evnt.Key, evnt.Game->Space.GameTime, true));
      }

      void DirectXInputEngine::KeyUp(KeyboardEvent & evnt)
      {
        Queue.push_back(KeyEventInfo(evnt.Key, evnt.Game->Space.GameTime, false));
      }

      void DirectXInputEngine::Update(Core::GameTime gameTime)
      {
        Keyboard::Last_ = Keyboard::Current_;

        for(auto& info : Queue)
        {
          Keyboard::Current_.SetKeyDown(info.Key, info.Pressed);
          if(info.Pressed)
            Keyboard::CurrentCombo_.Keys.push_back(KeyEventInfo(info.Key, gameTime));
        }
        Queue.clear();

        while(Keyboard::CurrentCombo_.Keys.size() > Keyboard::maxKeyComboLength)
          Keyboard::CurrentCombo_.Keys.erase(Keyboard::CurrentCombo_.Keys.begin());

        if(Keyboard::CurrentCombo_.Keys.size() > 0 &&
           gameTime - Keyboard::CurrentCombo_.Keys.back().TimePressed > Keyboard::KeyCoolDown)
        {
          Keyboard::CurrentCombo_.Keys.clear();
        }
      }

      DirectXInputEngine::DirectXInputEngine(Core::GameWindow& gameWindow) : GameWindow(gameWindow)
      {
        KeyDownCallback = new Core::Delegate<KeyboardEvent&>([](void * obj, KeyboardEvent &evnt)
        {
          static_cast<DirectXInputEngine*>(obj)->KeyDown(evnt);
        }, this);
        gameWindow.OnKeyDown += KeyDownCallback;

        KeyUpCallback = new Core::Delegate<KeyboardEvent&>([](void * obj, KeyboardEvent &evnt)
        {
          static_cast<DirectXInputEngine*>(obj)->KeyUp(evnt);
        }, this);
        gameWindow.OnKeyUp += KeyUpCallback;
      }

      DirectXInputEngine::~DirectXInputEngine()
      {
        GameWindow.OnKeyDown -= KeyDownCallback;
        GameWindow.OnKeyUp -= KeyUpCallback;
        delete KeyDownCallback;
        delete KeyUpCallback;
      }
    }
  }
}
