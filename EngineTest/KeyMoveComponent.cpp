#include "KeyMoveComponent.h"
#include "../MistThread/Input.h"

using Keyboard = MistThread::Input::Keyboard;
using Key = MistThread::Input::Key;

void KeyMoveComponent::Update(UpdateEvent * event)
{
  if(Keyboard::Current.IsKeyDown(Key::W))
  {
    Transform->Position.Y -= static_cast<float>(10 * event->GameTime.ElapsedTime);
  }
  if(Keyboard::Current.IsKeyDown(Key::S))
  {
    Transform->Position.Y += static_cast<float>(10 * event->GameTime.ElapsedTime);
  }
  if(Keyboard::Current.IsKeyDown(Key::A))
  {
    Transform->Position.X -= static_cast<float>(10 * event->GameTime.ElapsedTime);
  }
  if(Keyboard::Current.IsKeyDown(Key::D))
  {
    Transform->Position.X += static_cast<float>(10 * event->GameTime.ElapsedTime);
  }
}

void KeyMoveComponent::Initialize()
{
  Transform = static_cast<MistThread::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));

  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<KeyMoveComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}

KeyMoveComponent::KeyMoveComponent(MistThread::Core::GameObjects::GameObjectBase * owner) : Component(owner, "Transform")
{
  Name = "KeyMove";
}

KeyMoveComponent::~KeyMoveComponent()
{

}
