#include "Event.h"
#include "Game.h"

namespace MistThread
{
  namespace Core
  {
    Event::Event()
    {
      Game = Core::Game::CurrentGame;
    }
  }
}
