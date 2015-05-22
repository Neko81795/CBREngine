#pragma once
#include "../CBREngine/Core.h"


using Event = CBREngine::Core::Event;
using UpdateEvent = CBREngine::Core::GameObjects::Components::UpdateEvent;


class SinXComponent : public CBREngine::Core::GameObjects::Components::Component
{
public:
  CBREngine::Core::GameObjects::Components::TransformComponent* Transform;
  float Period;
  float Scale;
  float Offset;
  void Update(UpdateEvent * event);
  void Initialize() override;
  SinXComponent(CBREngine::Core::GameObjects::GameObject* owner);
  ~SinXComponent() {}
};

