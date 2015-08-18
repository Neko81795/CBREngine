#pragma once
#include "../MistThread/Core.h"

#include <list>

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
  //Other components
  MistThread::Core::GameObjects::Components::TransformComponent* transform_; //A transform dependency.

  //Internal data
  unsigned int activeParticles_;        //A vector of all the particles generated.
  unsigned int totalParticlesProduced_; //The number of particles produced in the life of the particle system.
  double lastGenerationTime_;           //The time particles were generated last.

  //Parsed data
  MistThread::IO::XML::XMLElement elementXML_; //A copy of the XML markup to generate the particle with.
  unsigned int maxParticles_;                  //The maximum number of particles that can be on the screen from this particle system.
  unsigned int maxGeneratedPerFrame_;          //The maximum number of particles generated in a given frame.
  double generationRadius_;                    //Radius in which particles are generated.
  double life_;                                //The life of the particles, in milliseconds.
  double lifeVariation_;                       //The ammount by which the life of the particle can be randomized in the positive or negative direction, in milliseconds.
  double emissionDelay_;                       //The delay between emitted particles, in milliseconds.     
  bool repeating_;                             //Whether or not the particle system will keep producing particles after it has hit the max.
  bool generateImmediately_;                   //Whether or not all the particles in the system should be generated up front or later.
};