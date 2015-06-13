#include "SpinComponent.h"


void SpinComponent::Update(UpdateEvent *)
{
  Transform->Rotation += RotationSpeed;
  RotationSpeed += Acceleration;
}

void SpinComponent::Initialize()
{
  Transform = static_cast<MistThread::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));

  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<SpinComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}

SpinComponent::SpinComponent(MistThread::Core::GameObjects::GameObjectBase * owner) : Component(owner, "Transform")
{
  Name = "Spin";
}
