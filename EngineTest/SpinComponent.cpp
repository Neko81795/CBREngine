#include "SpinComponent.h"


void SpinComponent::Update(UpdateEvent *)
{
  Transform->Rotation += RotationSpeed;
  RotationSpeed += Acceleration;
}

void SpinComponent::Initialize()
{
  Transform = static_cast<CBREngine::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));

  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<SpinComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}

SpinComponent::SpinComponent(CBREngine::Core::GameObjects::GameObject * owner) : Component(owner, "Transform")
{
  Name = "Spin";
}
