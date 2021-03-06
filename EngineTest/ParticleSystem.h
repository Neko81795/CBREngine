#pragma once
#include "../MistThread/Core.h"
#include "../MistThread/Core/GameObjects/Components/ObjectDestroyedEvent.h"
#include "Random.h"
#include <chrono>
#include <random>
#include <list>

using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;
using ObjectDestroyedEvent = MistThread::Core::GameObjects::Components::ObjectDestroyedEvent;



class ParticleSystem : public MistThread::Core::GameObjects::Components::Component
{
public:
  //Constructors
  /// <summary>
  /// Constructs the component.
  /// </summary>
  /// <param name="owner">The Object this component is attached to.</param>
  ParticleSystem(MistThread::Core::GameObjects::GameObjectBase* owner);
  /// <summary>
  /// Default destructor for the component.
  /// </summary>
  ~ParticleSystem() { }

  //Member Functions
  /// <summary>
  /// Updates the component via UpdateEvent.
  /// </summary>
  /// <param name="event">An event dealing with the updating of this component.</param>
  void Update(UpdateEvent * event);
  /// <summary>
  /// Initializes the ParticleSystemComponent.
  /// </summary>
  void Initialize() override;
  /// <summary>
  /// Creates a particle for the system with the specified parameters.
  /// </summary>
  void CreateParticle();
  /// <summary>
  /// Recieves an event every time a particle dies- monitors the number alive.
  /// </summary>
  void MonitorParticles(ObjectDestroyedEvent *event);
  /// <summary>
  /// Sets up the component from with the given XML Element.
  /// </summary>
  /// <param name="element">The element with the data needed to initialize.</param>
  virtual void DeSerialize(const MistThread::IO::XML::XMLElement & element) override;
  /// <summary>
  /// Populates the given XML Element with data for saving.
  /// </summary>
  /// <param name="element">The element to fill with data.</param>
  virtual void Serialize(MistThread::IO::XML::XMLElement & element) const override;

private:
  //Other components
  MistThread::Core::GameObjects::Components::TransformComponent* transform_; //A transform dependency.

  //Internal data
  unsigned int activeParticles_;        //A number handling all the particles generated.
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