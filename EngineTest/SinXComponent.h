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
  /// <summary>
  /// Sets up the component from with the given XML Element
  /// </summary>
  /// <param name="element">the element with the data needed to initialize</param>
  virtual void DeSerialize(const MistThread::IO::XML::XMLElement & element) override;
  /// <summary>
  /// Populates the given XML Element with data for saving
  /// </summary>
  /// <param name="element">the element to fill with data</param>
  virtual void Serialize(MistThread::IO::XML::XMLElement & element) const override;

  SinXComponent(MistThread::Core::GameObjects::GameObjectBase* owner);
  ~SinXComponent() {}
};

