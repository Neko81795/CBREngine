#pragma once
#include "../MistThread/Core.h"

using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;

class KeyMoveComponent : public MistThread::Core::GameObjects::Components::Component
{
public:
  MistThread::Core::GameObjects::Components::TransformComponent* Transform;
  void Update(UpdateEvent * event);
  void Initialize() override;
  KeyMoveComponent(MistThread::Core::GameObjects::GameObjectBase* owner);
  ~KeyMoveComponent();
};

