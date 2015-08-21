#pragma once
#include <list>
#include "GameObjects/GameObjectBase.h"
#include "../Graphics/Color.h"

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

  namespace Input
  {
    namespace Engines
    {
      class InputEngineCore; //forward declaration
    }
  }

  namespace Core
  {
    namespace GameObjects
    {
      class Space; //forward declaration
    }

    class GameWindow; //forward declaration

    class Game : public GameObjects::GameObjectBase
    {
      friend GameObjectBase;
//////////////////////////////////////////////////////////////
//Variables
//////////////////////////////////////////////////////////////
    private:
      /// <summary>
      /// Holds the constructors for all the components that have been registered
      /// </summary>
      static std::map < std::string, GameObjects::Components::Component*(*)(GameObjectBase*)> ComponetConstructors;
      /// <summary>
      /// the run loop of the game
      /// </summary>
      /// <param name="run">pointer to the indicator to run</param>
      void Run(bool * run);
    public:
      static Game *CurrentGame;

      Graphics::Engines::GraphicsEngineCore *Graphics;
      Audio::Engines::AudioEngineCore *Audio;
      Input::Engines::InputEngineCore *Input;
      GameWindow *Window;
      MistThread::Graphics::Color ClearColor;

//////////////////////////////////////////////////////////////
//Methods
//////////////////////////////////////////////////////////////
    private:
      /// <summary>
      /// the main game loop.
      /// </summary>
      friend void Run(bool *run, Game * game);

    public:
      template<typename T>
      static void RegisterComponent(std::string name);

      /// <summary>
      /// Starts the main game loop.
      /// Blocks until the game exits
      /// </summary>
      void Start();
      /// <summary>
      /// Creates a new space with the given name
      /// </summary>
      GameObjects::Space &CreateNamedSpace(const std::string& name);
      /// <summary>
      /// returns a reference to the space named
      /// </summary>
      /// <param name="name">the name of the space to find</param>
      /// <exception cref="Core::Exception">Thrown when the space cannot be found</exception>
      GameObjects::Space &FindSpaceByName(const std::string& name);
      /// <summary>
      /// removes the space with the name given
      /// </summary>
      /// <param name="name">the name of the space to remove</param>
      void RemoveSpaceByName(const std::string& name);
      /// <summary>
      /// compares this object to another for sorting
      /// value will be less than, greater than, or equal to 0.
      /// </summary>
      int CompareTo(const GameObjectBase* other)const override;
//////////////////////////////////////////////////////////////
//Constructors
//////////////////////////////////////////////////////////////
      /// <summary>
      /// Creates a Game
      /// </summary>
      /// <param name="window"> The window to draw the game on </param>
      /// <param name="graphics"> The Graphics implementation for the game </param>
      Game(GameWindow *window, Graphics::Engines::GraphicsEngineCore *graphics, Audio::Engines::AudioEngineCore *audio, Input::Engines::InputEngineCore *input);
      ~Game();
    };

//////////////////////////////////////////////////////////////
//Template Definitions
//////////////////////////////////////////////////////////////
    /// <summary>
    /// Allows the Game to use the Component
    /// </summary>
    /// <param name="name">the name of the component</param>
    template<typename T>
    void Game::RegisterComponent(std::string name)
    {
      Game::ComponetConstructors[name] = [](GameObjectBase* owner) -> GameObjects::Components::Component* { return new T(owner); };
    }
  }
}

