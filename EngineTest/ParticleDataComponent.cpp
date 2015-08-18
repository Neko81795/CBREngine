#include "ParticleDataComponent.h"


void ParticleDataComponent::Update(UpdateEvent * event)
{
  Transform->Position += Velocity;
  if (event->GameTime.TotalTime > TimeStarted + Life)
  {
    MistThread::Core::GameObjects::GameObject *obj = dynamic_cast<MistThread::Core::GameObjects::GameObject *>(&Owner);
    if (obj)
      obj->Destroy();
  }
}

ParticleDataComponent::ParticleDataComponent(MistThread::Core::GameObjects::GameObjectBase* owner) : Component(owner, "Transform")
{
  Name = "ParticleData";
}

void ParticleDataComponent::Initialize()
{
  Transform = static_cast<MistThread::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));
  TimeStarted = Space.GameTime.TotalTime;

  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<ParticleDataComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}