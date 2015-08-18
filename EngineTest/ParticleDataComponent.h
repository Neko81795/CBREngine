#pragma once
#include "../MistThread/Core.h"

using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;



struct ParticleDataComponent : public MistThread::Core::GameObjects::Components::Component
{
  //Constructors
  ParticleDataComponent(MistThread::Core::GameObjects::GameObjectBase* owner);
  ~ParticleDataComponent() { }

  //Member Functions
  void Initialize() override;
  void Update(UpdateEvent * event);

  //Variables
  MistThread::Core::GameObjects::Components::TransformComponent* Transform;
  MistThread::Core::Vector2 Velocity;
  double Life;
  double TimeStarted;
};