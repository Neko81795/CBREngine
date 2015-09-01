#pragma once
#include "../MistThread/Core.h"
#include <sstream>
#include "Random.h"

using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;

class SpinComponent : public MistThread::Core::GameObjects::Components::Component
{
public:
  MistThread::Core::GameObjects::Components::TransformComponent* Transform;
  float RotationSpeed;
  float RotationVariation;
  float RotationVariationAmount;
  float Acceleration;
  void Update(UpdateEvent * event);
  void Initialize() override;

  /// <summary>
  /// Sets up the component from with the given XML Element
  /// </summary>
  /// <param name="element">the element with the data needed to initialize</param>
  virtual void InitializeFromXML(const MistThread::IO::XML::XMLElement & element) override;
  /// <summary>
  /// Populates the given XML Element with data for saving
  /// </summary>
  /// <param name="element">the element to fill with data</param>
  virtual void PopulateXML(MistThread::IO::XML::XMLElement & element) const override;

  SpinComponent(MistThread::Core::GameObjects::GameObjectBase* owner);
  ~SpinComponent() {}
};

