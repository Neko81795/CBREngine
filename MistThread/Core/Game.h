#pragma once
#include <list>
#include "GameObjects/GameObjectBase.h"

namespace MistThread
{
  namespace Graphics
  {
    namespace Engines
    {
      class GraphicsEngineCore; //forward declaration
    }
  }
  namespace Core
  {
    namespace GameObjects
    {
      class Space; //forward declaration
    }

    class GameWindow; //forward declaration

    class Game : GameObjects::GameObjectBase
    {
//////////////////////////////////////////////////////////////
//Variables
//////////////////////////////////////////////////////////////
    public:
      static Game *CurrentGame;

      Graphics::Engines::GraphicsEngineCore *Graphics;
      GameWindow *Window;
      std::list<GameObjects::Space> Spaces;

//////////////////////////////////////////////////////////////
//Methods
//////////////////////////////////////////////////////////////
    private:
      /// <summary>
      /// the main game loop.
      /// </summary>
      friend void Run(bool *run, Game * game);
      /// <summary>
      /// Helper function to create main space. used in constructor :D
      /// </summary>
      GameObjects::Space &CreateMainSpace();

    public:
      /// <summary>
      /// Starts the main game loop.
      /// Blocks until the game exits
      /// </summary>
      void Start();

//////////////////////////////////////////////////////////////
//Constructors
//////////////////////////////////////////////////////////////
      /// <summary>
      /// Creates a Game
      /// </summary>
      /// <param name="window"> The window to draw the game on </param>
      /// <param name="graphics"> The Graphics implementation for the game </param>
      Game(GameWindow *window, Graphics::Engines::GraphicsEngineCore *graphics);
      ~Game();
    };
  }
}

