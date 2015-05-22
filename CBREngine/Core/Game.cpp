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


namespace CBREngine
{
  namespace Core
  {
    void Run(bool * run, Game * game)
    {
      CBREngine::Graphics::Color clearColor(75, 120, 255);
      float rot = 0;

      CBREngine::Graphics::Bitmap b(*game->Graphics);


      game->Graphics->LoadBitmapFromFile("C:\\Users\\Neko\\Documents\\Visual Studio 2015\\Projects\\CBREngine\\x64\\Debug\\bit.png", b);
      CBREngine::Core::Size2 s = b.GetSize() / 2;
      CBREngine::Core::Vector2 bcenter((float)s.Width, (float)s.Height);
      CBREngine::Core::RectangleF rect(400, 500, 400, 400);
      CBREngine::Core::GameTime g;

      game->Spaces.front().Initialize();

      while (*run)
      {
        g.Tick();

        for (GameObjects::Space &space : game->Spaces)
        {
          space.Update(g);
        }
        game->Graphics->BeginDraw();
        game->Graphics->Clear(clearColor);



        game->Graphics->DrawBitmap(b, CBREngine::Core::Vector2(400, 500), 1, bcenter, -rot, CBREngine::Core::Vector2(0.25f, 0.5f));
        game->Graphics->DrawBitmap(b, CBREngine::Core::Vector2(400, 500), 1, CBREngine::Core::Vector2(200, 200), rot++, CBREngine::Core::Vector2(0.25f, 1), &rect);

        for (GameObjects::Space &space : game->Spaces)
        {
          space.Draw(*game->Graphics);
        }
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

    Game::Game(GameWindow *window, Graphics::Engines::GraphicsEngineCore *graphics)
    {
      Graphics = graphics;
      Window = window;
      CurrentGame = this;

      GameObjects::Space main(*this, Graphics);
      main.Name = "Main";

      Spaces.push_back(main);
    }

    Game::~Game()
    {

    }

    Game *Game::CurrentGame;
  }
}
