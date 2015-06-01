#include "../CBREngine/Core.h"
#include "../CBREngine/Graphics.h"
#include "SpinComponent.h"
#include "SinXComponent.h"

//TODO REMOVE THIS SHIT IT'S BAD PRACTICE
using namespace CBREngine;
using namespace CBREngine::Core;
using namespace CBREngine::Core::GameObjects;
using namespace CBREngine::Core::GameObjects::Components;

int WINAPI WinMain(HINSTANCE /*hInstance*/, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nShowCmd)
{
  GameWindow gameWindow("CBREngine Test oh boy");
  CBREngine::Graphics::Engines::DirectXGraphicsEngine graphics(gameWindow);
  Game game(&gameWindow, &graphics);


  GameObject &obj = game.Spaces.front().CreateObject();
  TransformComponent& trans = obj.AddComponent<TransformComponent>();
  trans.Position.X = 3;
  trans.Position.Y = 3;
  trans.Scale.Height = 3;
  trans.Scale.Width = 3;
  DrawComponent& draw = obj.AddComponent<DrawComponent>();
  draw.Color = Graphics::Color(0xFF006A6A);

  GameObject &obj2 = game.Spaces.front().CreateObject();
  TransformComponent& trans2 = obj2.AddComponent<TransformComponent>();
  trans2.Position.X = 12;
  trans2.Position.Y = 16;
  trans2.Scale.Height = 16;
  trans2.Scale.Width = 2;
  DrawComponent& draw2 = obj2.AddComponent<DrawComponent>();
  draw2.Color = Graphics::Color(0xFFFF00FF);
  draw2.Mode = DrawComponent::Fill;
  SpinComponent& spin2 = obj2.AddComponent<SpinComponent>();
  spin2.RotationSpeed = 1;

  GameObject &obj3 = game.Spaces.front().CreateObject();
  TransformComponent& trans3 = obj3.AddComponent<TransformComponent>();
  trans3.Position.X = 8;
  trans3.Position.Y = 8;
  trans3.Scale.Height = 12;
  trans3.Scale.Width = 6;
  DrawComponent& draw3 = obj3.AddComponent<DrawComponent>();
  draw3.Color = Graphics::Color(0xFFFFFF00);
  draw3.Mode = DrawComponent::Fill;
  draw3.Type = DrawComponent::Elipse;
  SpinComponent& spin3 = obj3.AddComponent<SpinComponent>();
  spin3.RotationSpeed = 1;
  spin3.Acceleration = 0.2f;
  SinXComponent& sin3 = obj3.AddComponent<SinXComponent>();
  sin3.Period = 1;
  sin3.Scale = 9;
  sin3.Offset = 18;

  GameObject &obj4 = game.Spaces.front().CreateObject();
  TransformComponent& trans4 = obj4.AddComponent<TransformComponent>();
  trans4.Position.X = 8;
  trans4.Position.Y = 8;
  trans4.Scale.Height = 12;
  trans4.Scale.Width = 6;
  DrawComponent& draw4 = obj4.AddComponent<DrawComponent>();
  draw4.Color = Graphics::Color(0xFF006A6A);
  draw4.Stroke = 30;
  draw4.Type = DrawComponent::Elipse;
  SpinComponent& spin4 = obj4.AddComponent<SpinComponent>();
  spin4.RotationSpeed = 1;
  spin4.Acceleration = 0.2f;
  SinXComponent& sin4 = obj4.AddComponent<SinXComponent>();
  sin4.Period = 1.01f;
  sin4.Scale = 9;
  sin4.Offset = 18;

  GameObject &obj5 = game.Spaces.front().CreateObject();
  TransformComponent& trans5 = obj5.AddComponent<TransformComponent>();
  trans5.Position.X = 8;
  trans5.Position.Y = 8;
  trans5.Scale.Height = 0.5;
  trans5.Scale.Width = 0.5;
  DrawBitmapComponent& draw5 = obj5.AddComponent<DrawBitmapComponent>();
  Graphics::Bitmap b(graphics);
  graphics.LoadBitmapFromFile("C:/Users/Neko/Documents/Visual Studio 2015/Projects/CBREngine/x64/Debug/bit.png", b);
  draw5.Image = &b;
  SpinComponent& spin5 = obj5.AddComponent<SpinComponent>();
  spin5.RotationSpeed = 1;
  SinXComponent& sin5 = obj5.AddComponent<SinXComponent>();
  sin5.Period = 1.01f;
  sin5.Scale = 9;
  sin5.Offset = 18;
  

  game.Start();

  return 0;
}
