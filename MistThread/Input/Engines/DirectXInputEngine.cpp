#include "DirectXInputEngine.h"
#include "../../Core/GameWindow.h"
#include "../KeyboardEventHandler.h"
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
        Keyboard::Last = Keyboard::Current;

        for(auto& info : Queue)
        {
          Keyboard::Current.SetKeyDown(info.Key, info.Pressed);
          if(info.Pressed)
            Keyboard::CurrentCombo.Keys.push_back(KeyEventInfo(info.Key, gameTime));
        }
        Queue.clear();

        while(Keyboard::CurrentCombo.Keys.size() > Keyboard::maxKeyComboLength)
          Keyboard::CurrentCombo.Keys.erase(Keyboard::CurrentCombo.Keys.begin());

        if(Keyboard::CurrentCombo.Keys.size() > 0 &&
           gameTime - Keyboard::CurrentCombo.Keys.back().TimePressed > Keyboard::KeyCoolDown)
        {
          Keyboard::CurrentCombo.Keys.clear();
        }
      }

      DirectXInputEngine::DirectXInputEngine(Core::GameWindow& gameWindow)
      {
        gameWindow.OnKeyDown += Core::Delegate<KeyboardEvent&>([](void * obj, KeyboardEvent &evnt)
        {
          static_cast<DirectXInputEngine*>(obj)->KeyDown(evnt);
        }, this);

        gameWindow.OnKeyUp += Core::Delegate<KeyboardEvent&>([](void * obj, KeyboardEvent &evnt)
        {
          static_cast<DirectXInputEngine*>(obj)->KeyUp(evnt);
        }, this);
      }

      DirectXInputEngine::~DirectXInputEngine()
      {
        
      }
    }
  }
}
