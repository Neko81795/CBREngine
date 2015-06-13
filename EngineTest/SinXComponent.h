#pragma once
#include "../MistThread/Core.h"


using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;


class SinXComponent : public MistThread::Core::GameObjects::Components::Component
{
public:
  MistThread::Core::GameObjects::Components::TransformComponent* Transform;
  float Period;
  float Scale;
  float Offset;
  void Update(UpdateEvent * event);
  void Initialize() override;
  SinXComponent(MistThread::Core::GameObjects::GameObjectBase* owner);
  ~SinXComponent() {}
};

