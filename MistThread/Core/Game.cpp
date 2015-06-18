#include "Game.h"

#if WIN32
#include <Windows.h>
#include <atlbase.h>
#include <atlwin.h>
#endif

#include <future>

#include "../Graphics.h"
#include "GameObjects/Space.h"
#include "Delegate.h"
#include "GameObjects/Components/Component.h"


namespace MistThread
{
  namespace Core
  {
    void Run(bool * run, Game * game)
    {
      MistThread::Graphics::Color clearColor(75, 120, 255);
      MistThread::Core::GameTime g;

      game->Initialize();

      while (*run)
      {
        g.Tick();

        for (GameObjects::GameObjectBase *space : game->Objects)
        {
          static_cast<GameObjects::Space*>(space)->Update(g);
        }
        game->Graphics->BeginDraw();
        game->Graphics->Clear(clearColor);

        game->Draw(*game->Graphics);

        game->Graphics->EndDraw();
      }
    }

#if WIN32
    void Game::Start()
    {
      bool run;
      MSG msg;

      auto f = std::async(Run, &run, this);
      
      while (run)
      {
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
          TranslateMessage(&msg);
          DispatchMessage(&msg);
          if (msg.message == WM_QUIT)
            run = false;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
      }
    }
#endif

    GameObjects::Space &Game::CreateNamedSpace(const std::string &name)
    {
      GameObjects::Space *space = new GameObjects::Space(*this);
      space->Name = name;

      Objects.push_back(space);
      RegisterDraw(space);

      return *space;
    }

    GameObjects::Space &Game::FindSpaceByName(const std::string &name)
    {
      for(auto space : Objects)
      {
        if(space->Name == name)
          return *dynamic_cast<GameObjects::Space*>(space);
      }
      throw std::exception("Space could not be found");
    }

    void Game::RemoveSpaceByName(const std::string &name)
    {
      RemoveGameObjectBaseByName(name);
    }

    int Game::CompareTo(const GameObjectBase* other)const
    {
      if(other->Type != "Game")
        return 1;

      //all games are equal
      return 0;
    }

    Game::Game(GameWindow *window, Graphics::Engines::GraphicsEngineCore *graphics, Audio::Engines::AudioEngineCore *audio) : GameObjectBase(*this, *new GameObjects::Space(*this))
    {
      Type = "Game";
      Name = "Game";
      Space.Name = "Main";
      Objects.push_back(&Space);
      RegisterDraw(&Space);
      Graphics = graphics;
      Window = window;
      CurrentGame = this;

      Audio = audio;
    }

    Game::~Game()
    {

    }

    Game *Game::CurrentGame;
  }
}
