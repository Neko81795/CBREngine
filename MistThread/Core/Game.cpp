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
#include "GameObjects/Components.h"
#include "../Input/Engines/InputEngineCore.h"
#include "Exception.h"
#include "../Utilities/ContentManager.h"


namespace MistThread
{
  namespace Core
  {
    void Game::Run(bool *run)
    {
      try
      {
        Initialize();

        while(*run)
        {
          Input->Update(Space.GameTime);

          for(GameObjects::GameObjectBase *space : Objects)
          {
            dynamic_cast<GameObjects::Space*>(space)->Update();
          }
          Graphics->BeginDraw();
          Graphics->Clear(ClearColor);

          Draw(*Graphics);

          Graphics->EndDraw();
        }
      }
      catch(Exception ex)
      {
        //todo MAKE A WINDOW
        int i = 0;
        ++i;
      }
      
      Utilities::ContentManager::Unload();
    }

    void Run(bool * run, Game * game)
    {
      game->Run(run);
    }

    bool Game::GetIsRunning()
    {
      return IsRunning;
    }

#if WIN32
    void Game::Start()
    {
      bool run;
      MSG msg;

      IsRunning = true;
      auto f = std::async(Core::Run, &run, this);
      
      while(run)
      {
        while(PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
          TranslateMessage(&msg);
          DispatchMessage(&msg);
          if(msg.message == WM_QUIT)
            run = false;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
      }
    }
#endif

    GameObjects::Space &Game::CreateNamedSpace(const std::string &name)
    {
      GameObjects::Space *space = new GameObjects::Space(*this);
      space->Name = name;

      auto &obj = space->CreateObjectAt(Vector2::Zero, 30);
      obj.Name = "Camera";
      obj.AddComponentByName("Camera");

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
      throw Exception("Space could not be found");
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

    Game::Game(GameWindow *window, Graphics::Engines::GraphicsEngineCore *graphics, Audio::Engines::AudioEngineCore *audio, Input::Engines::InputEngineCore *input) : GameObjectBase(*this, *new GameObjects::Space(*this)), ClearColor(75, 120, 255)
    {
      RegisterComponent<GameObjects::Components::TransformComponent>("Transform");
      RegisterComponent<GameObjects::Components::DrawBitmapComponent>("DrawBitmap");
      RegisterComponent<GameObjects::Components::DrawComponent>("Draw");
      RegisterComponent<GameObjects::Components::DrawTextComponent>("DrawText");
      RegisterComponent<GameObjects::Components::ConsoleComponent>("Console");
      RegisterComponent<GameObjects::Components::CameraComponent>("Camera");

      Type = "Game";
      Name = "Game";
      Space.Name = "Main";

      auto &obj = Space.CreateObjectAt(Vector2::Zero, 30);
      obj.Name = "Camera";
      obj.AddComponentByName("Camera");

      Objects.push_back(&Space);
      RegisterDraw(&Space);
      Graphics = graphics;
      Window = window;
      CurrentGame = this;

      Audio = audio;

      Input = input;


      AddComponentByName("Console");

    }

    Game::~Game()
    {

    }


    Game *Game::CurrentGame;
    std::map<std::string, GameObjects::Components::Component*(*)(GameObjects::GameObjectBase*)> Game::ComponetConstructors;
  }
}
