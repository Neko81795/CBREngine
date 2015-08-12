#pragma once
#include "../MistThread/Core.h"

#include <vector>

using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;



class ParticleSystem : public MistThread::Core::GameObjects::Components::Component
{
public:
  ParticleSystem(MistThread::Core::GameObjects::GameObjectBase* owner);
  ~ParticleSystem() { }

  void Update(UpdateEvent * event);
  void Initialize() override;
  void CreateParticle();
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


private:
  MistThread::Core::GameObjects::Components::TransformComponent* transform_;
  std::vector<MistThread::Core::GameObjects::GameObject *> particles_;
  MistThread::IO::XML::XMLElement elementXML_; //A copy of the XML markup to generate the particle with.
  double emissionDelay_;
  int maxParticles_;
  int life_;
  int lifeVariation_;
  bool repeating_;
};