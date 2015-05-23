#include "SinXComponent.h"


void SinXComponent::Update(UpdateEvent * event)
{
  Transform->Position.X = std::sinf(static_cast<float>(event->GameTime.TotalTime) * (2 * 3.1415926535f / Period)) * Scale + Offset;
}

void SinXComponent::Initialize()
{
  Transform = static_cast<CBREngine::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));

  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<SinXComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}

SinXComponent::SinXComponent(CBREngine::Core::GameObjects::GameObject * owner) : Component(owner, "Transform")
{
  Name = "SinX";
}
