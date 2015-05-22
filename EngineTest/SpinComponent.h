#pragma once
#include "../CBREngine/Core.h"


using Event = CBREngine::Core::Event;
using UpdateEvent = CBREngine::Core::GameObjects::Components::UpdateEvent;

class SpinComponent : public CBREngine::Core::GameObjects::Components::Component
{
public:
  CBREngine::Core::GameObjects::Components::TransformComponent* Transform;
  float RotationSpeed;
  float Acceleration;
  void Update(UpdateEvent * event);
  void Initialize() override;

  SpinComponent(CBREngine::Core::GameObjects::GameObject* owner);
  ~SpinComponent() {}
};

