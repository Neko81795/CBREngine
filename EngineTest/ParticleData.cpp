#include "ParticleData.h"


void ParticleData::Update(UpdateEvent * event)
{
  Transform->Position += Velocity;
}

ParticleData::ParticleData(MistThread::Core::GameObjects::GameObjectBase* owner) : Component(owner, "Transform")
{
  Name = "ParticleSystem";
}

void ParticleData::Initialize()
{
  TimeStarted = Space.GameTime.TotalTime;
  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<ParticleData *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}