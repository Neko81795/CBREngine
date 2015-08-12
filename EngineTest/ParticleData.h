#pragma once
#include "../MistThread/Core.h"

using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;



struct ParticleData : public MistThread::Core::GameObjects::Components::Component
{
  //Constructors
  ParticleData(MistThread::Core::GameObjects::GameObjectBase* owner);
  ~ParticleData() { }
  //Member Functions
  void Update(UpdateEvent * event);
  void Initialize() override;


  //Variables
  MistThread::Core::GameObjects::Components::TransformComponent* Transform;
  MistThread::Core::Vector2 Velocity;
  int Life;
  int TimeStarted;
};