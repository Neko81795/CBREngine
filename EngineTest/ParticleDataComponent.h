#pragma once
#include "../MistThread/Core.h"

using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;



struct ParticleDataComponent : public MistThread::Core::GameObjects::Components::Component
{
  public:
    //Constructors
    /// <summary>
    /// Constructs the component.
    /// </summary>
    /// <param name="owner">The Object this component is attached to.</param>
    ParticleDataComponent(MistThread::Core::GameObjects::GameObjectBase* owner);
    /// <summary>
    /// Default destructor for the component.
    /// </summary>
    ~ParticleDataComponent() { }

    //Member Functions
    /// <summary>
    /// Initializes the ParticleDataComponent.
    /// </summary>
    void Initialize() override;
    /// <summary>
    /// Updates the component via UpdateEvent.
    /// </summary>
    /// <param name="event">An event dealing with the updating of this component. Has time data and other info.</param>
    void Update(UpdateEvent * event);

    //Variables
    MistThread::Core::GameObjects::Components::TransformComponent* Transform; //A reference to the owner's transform component.
    MistThread::Core::Vector2 Velocity;                                       //The object's velocity, which could be applied by the particle system.
    double Life;                                                              //The particle's life, which could be applied by the particle system.
    double TimeStarted;                                                       //The time which this particle was created, in game-time (seconds).
};