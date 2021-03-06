#include "../MistThread/Core.h"
#include "../MistThread/Graphics.h"
#include "SpinComponent.h"
#include "SinXComponent.h"
#include "ZLayerComponent.h"
#include "KeyMoveComponent.h"
#include "SoundPulseComponent.h"
#include "ParticleSystem.h"
#include "ParticleDataComponent.h"
#include "ForceComponent.h"
#include "Random.h"
#include "../MistThread/Input.h"
#include "../MistThread/Audio/Sound.h"
#include "../MistThread/Audio/Engines/FMODAudioEngine.h"
#include "../MistThread/IO.h"
#include "../MistThread/Utilities.h"
#include <string>

//TODO REMOVE THIS SHIT IT'S BAD PRACTICE
using namespace MistThread;
using namespace MistThread::Core;
using namespace MistThread::Core::GameObjects;
using namespace MistThread::Core::GameObjects::Components;

using XMLElement = MistThread::IO::XML::XMLElement;
using AppInfo = MistThread::Utilities::AppInfo;
using ContentManager = MistThread::Utilities::ContentManager;

//YUP YUP MORE BAD PRACTICE HERE
using namespace MistThread::Audio;
using namespace MistThread::Audio::Engines;
//If you wanna see some real bad practice you should see GameObjectBase.cpp

int WINAPI WinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nShowCmd)
{
  //TODO: (Matthew) -- Sound does not properly dispose when the component it is attached to is deleted. Check out the 
  //destructor in the Sound object to make sure everything is properly disposing, and all handles are being
  //delt with accordingly. Write test to do this.

  //get info about this application
  AppInfo appInfo;
  std::string hostName = appInfo.GetHostName();
  std::string WorkingDir = appInfo.GetCurrentWorkingDirectory();

  
  
  //note that this is not actually necessary as paths will default to this location
  ContentManager::RootFolder = WorkingDir;

  //set up the game
  GameWindow gameWindow("MistThread Test oh boy");
  MistThread::Graphics::Engines::DirectXGraphicsEngine graphics(gameWindow);
  MistThread::Audio::Engines::FMODAudioEngine audio = MistThread::Audio::Engines::FMODAudioEngine();
  MistThread::Input::Engines::DirectXInputEngine input(gameWindow);
  Game game(&gameWindow, &graphics, &audio, &input);

  //register our components
  Game::RegisterComponent<KeyMoveComponent>("KeyMove");
  Game::RegisterComponent<SpinComponent>("Spin");
  Game::RegisterComponent<ZLayerComponent>("ZLayer");
  Game::RegisterComponent<SinXComponent>("SinX");
  Game::RegisterComponent<SoundPulseComponent>("SoundPulse");
  Game::RegisterComponent<ParticleSystem>("ParticleSystem");
  Game::RegisterComponent<ParticleDataComponent>("ParticleData");
  Game::RegisterComponent<ForceComponent>("Force");

  //get the space and load a level
  Space &mainSpace = game.FindSpaceByName("Main");

  if (hostName == "Hera")
  {
    mainSpace.LoadLevel("Level.xml");
  }
  else if (hostName == "Ghost")
  {
    mainSpace.LoadLevel("Level3.xml");
  }
  else if (hostName == "Bird_Noises")
  {
    mainSpace.LoadLevel("Luna.xml");
  }
  else
  {
    mainSpace.LoadLevel("Level.xml");
  }
  //start the game
  game.Start();

  return 0;
}
