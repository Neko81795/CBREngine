#pragma once
#include "../MistThread/Core.h"


using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;

class SpinComponent : public MistThread::Core::GameObjects::Components::Component
{
public:
  MistThread::Core::GameObjects::Components::TransformComponent* Transform;
  float RotationSpeed;
  float Acceleration;
  void Update(UpdateEvent * event);
  void Initialize() override;

  SpinComponent(MistThread::Core::GameObjects::GameObjectBase* owner);
  ~SpinComponent() {}
};

