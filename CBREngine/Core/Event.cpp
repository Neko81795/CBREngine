#include "Event.h"
#include "Game.h"

namespace CBREngine
{
  namespace Core
  {
    Event::Event()
    {
      Game = Core::Game::CurrentGame;
    }
  }
}
