#pragma once
#include <list>

namespace MistThread
{
  namespace Graphics
  {
    namespace Engines
    {
      class GraphicsEngineCore; //forward declaration
    }
  }
  namespace Audio
  {
    namespace Engines
    {
      class AudioEngineCore; 
    }
  }

  namespace Core
  {
    namespace GameObjects
    {
      class Space; //forward declaration
    }

    class GameWindow; //forward declaration

    class Game
    {
      ///////////////////////////////
      //static Variable
      ///////////////////////////////
    public:
      static Game *CurrentGame;
      
      ///////////////////////////////
      //Variables
      ///////////////////////////////
    public:
      Graphics::Engines::GraphicsEngineCore *Graphics;
      Audio::Engines::AudioEngineCore *Audio;
      GameWindow *Window;
      std::list<GameObjects::Space> Spaces;

      ///////////////////////////////
      //Methods
      ///////////////////////////////
    private:
      /// <summary>
      /// the main game loop.
      /// </summary>
      friend void Run(bool *run, Game * game);
    public:
      /// <summary>
      /// Starts the main game loop.
      /// Blocks until the game exits
      /// </summary>
      void Start();

      /// <summary>
      /// Creates a Game
      /// </summary>
      /// <param name="window"> The window to draw the game on </param>
      /// <param name="graphics"> The Graphics implementation for the game </param>
      Game(GameWindow *window, Graphics::Engines::GraphicsEngineCore *graphics, Audio::Engines::AudioEngineCore *audio);
      ~Game();
    };
  }
}

