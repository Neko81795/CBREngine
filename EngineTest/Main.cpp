#include "../MistThread/Core.h"
#include "../MistThread/Graphics.h"
#include "SpinComponent.h"
#include "SinXComponent.h"
#include "../MistThread/Audio/Sound.h"
#include "../MistThread/Audio/Engines/FMODAudioEngine.h"
#include "ZLayerComponent.h"
#include "KeyMoveComponent.h"
#include "../MistThread/Input.h"

//TODO REMOVE THIS SHIT IT'S BAD PRACTICE
using namespace MistThread;
using namespace MistThread::Core;
using namespace MistThread::Core::GameObjects;
using namespace MistThread::Core::GameObjects::Components;

//YUP YUP MORE BAD PRACTICE HERE
using namespace MistThread::Audio;
using namespace MistThread::Audio::Engines;
//If you wanna see some real bad practice you should see GameObjectBase.cpp

int WINAPI WinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nShowCmd)
{
  GameWindow gameWindow("MistThread Test oh boy");
  MistThread::Graphics::Engines::DirectXGraphicsEngine graphics(gameWindow);
  MistThread::Audio::Engines::FMODAudioEngine audio = MistThread::Audio::Engines::FMODAudioEngine();
  MistThread::Input::Engines::DirectXInputEngine input(gameWindow);
  Game game(&gameWindow, &graphics, &audio, &input);

  Game::RegisterComponent<KeyMoveComponent>("KeyMove");
  Game::RegisterComponent<SpinComponent>("Spin");
  Game::RegisterComponent<ZLayerComponent>("ZLayer");
  Game::RegisterComponent<SinXComponent>("SinX");

  Sound s;
  //s.Play("AudioTest.ogg");
  Space &mainSpace = game.FindSpaceByName("Main");

  GameObject &obj = mainSpace.CreateObject();
  TransformComponent& trans = *obj.AddComponentByName<TransformComponent>("Transform");
  trans.Position.X = 0;
  trans.Position.Y = 0;
  trans.Scale.Height = 3;
  trans.Scale.Width = 3;
  DrawComponent& draw = *dynamic_cast<DrawComponent*>(obj.AddComponentByName("Draw")); //the other way of doing it for comparison
  draw.Color = Graphics::Color(0xFF006A6A);
  obj.AddComponentByName("KeyMove");

  GameObject &obj2 = mainSpace.CreateObject();
  TransformComponent& trans2 = *obj2.AddComponentByName<TransformComponent>("Transform");
  trans2.Position.X = 3;
  trans2.Position.Y = 3;
  trans2.Scale.Height = 16;
  trans2.Scale.Width = 2;
  DrawComponent& draw2 = *obj2.AddComponentByName<DrawComponent>("Draw");
  draw2.Color = Graphics::Color(0xFFFF00FF);
  draw2.Mode = DrawComponent::Fill;
  SpinComponent& spin2 = *obj2.AddComponentByName<SpinComponent>("Spin");
  spin2.RotationSpeed = 1;
  *obj2.AddComponentByName<ZLayerComponent>("ZLayer");

  GameObject &obj2_2 = mainSpace.CreateObject();
  TransformComponent& trans2_2 = *obj2_2.AddComponentByName<TransformComponent>("Transform");
  trans2_2.Position.X = 3;
  trans2_2.Position.Y = 3;
  trans2_2.Scale.Height = 16;
  trans2_2.Scale.Width = 2;
  DrawComponent& draw2_2 = *obj2_2.AddComponentByName<DrawComponent>("Draw");
  draw2_2.Color = Graphics::Color(0xFF00FFFF);
  draw2_2.Mode = DrawComponent::Fill;
  SpinComponent& spin2_2 = *obj2_2.AddComponentByName<SpinComponent>("Spin");
  spin2_2.RotationSpeed = -1;

  GameObject &obj3 = mainSpace.CreateObject();
  TransformComponent& trans3 = *obj3.AddComponentByName<TransformComponent>("Transform");
  trans3.Position.X = 8;
  trans3.Position.Y = 8;
  trans3.Scale.Height = 12;
  trans3.Scale.Width = 6;
  DrawComponent& draw3 = *obj3.AddComponentByName<DrawComponent>("Draw");
  draw3.Color = Graphics::Color(0xFFFFFF00);
  draw3.Mode = DrawComponent::Fill;
  draw3.Type = DrawComponent::Elipse;
  SpinComponent& spin3 = *obj3.AddComponentByName<SpinComponent>("Spin");
  spin3.RotationSpeed = 1;
  spin3.Acceleration = 0.2f;
  SinXComponent& sin3 = *obj3.AddComponentByName<SinXComponent>("SinX");
  sin3.Period = 1;
  sin3.Scale = 9;
  sin3.Offset = 18;

  GameObject &obj4 = mainSpace.CreateObject();
  TransformComponent& trans4 = *obj4.AddComponentByName<TransformComponent>("Transform");
  trans4.Position.X = 8;
  trans4.Position.Y = 8;
  trans4.Scale.Height = 12;
  trans4.Scale.Width = 6; 
  DrawComponent& draw4 = *obj4.AddComponentByName<DrawComponent>("Draw");
  draw4.Color = Graphics::Color(0xFF006A6A);
  draw4.Stroke = 30;
  draw4.Type = DrawComponent::Elipse;
  SpinComponent& spin4 = *obj4.AddComponentByName<SpinComponent>("Spin");
  spin4.RotationSpeed = 1;
  spin4.Acceleration = 0.2f;
  SinXComponent& sin4 = *obj4.AddComponentByName<SinXComponent>("SinX");
  sin4.Period = 1.01f;
  sin4.Scale = 9;
  sin4.Offset = 18;

  ////GameObject &obj5 = game.Spaces.front().CreateObject();
  ////TransformComponent& trans5 = obj5.AddComponent<TransformComponent>();
  ////trans5.Position.X = 8;
  ////trans5.Position.Y = 8;
  ////trans5.Scale.Height = 0.5;
  ////trans5.Scale.Width = 0.5;
  ////DrawBitmapComponent& draw5 = obj5.AddComponent<DrawBitmapComponent>();
  ////Graphics::Bitmap b(graphics);
  ////graphics.LoadBitmapFromFile("C:/Users/Neko/Documents/Visual Studio 2015/Projects/MistThread/x64/Debug/bit.png", b);
  ////draw5.Image = &b;
  ////SpinComponent& spin5 = obj5.AddComponent<SpinComponent>();
  ////spin5.RotationSpeed = 1;
  ////SinXComponent& sin5 = obj5.AddComponent<SinXComponent>();
  ////sin5.Period = 1.01f;
  ////sin5.Scale = 9;
  ////sin5.Offset = 18;
  

  game.Start();

  return 0;
}
