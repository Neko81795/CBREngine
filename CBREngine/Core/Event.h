#pragma once
namespace CBREngine
{
  namespace Core
  {
    class Game; //forward declaration

    class Event
    {
    public:
      bool Handled;
      Core::Game *Game;
      Event();
    };
  }
}
