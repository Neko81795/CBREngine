#pragma once
#include "../MistThread/Core.h"
#include <sstream>
#include "Random.h"

using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;



struct ForceComponent : public MistThread::Core::GameObjects::Components::Component
{
    //Constructors
    /// <summary>
    /// Constructs the component.
    /// </summary>
    /// <param name="owner">The Object this component is attached to.</param>
    ForceComponent(MistThread::Core::GameObjects::GameObjectBase* owner);
    /// <summary>
    /// Default destructor for the component.
    /// </summary>
    ~ForceComponent() { }

    //Member Functions
    /// <summary>
    /// Initializes the ForceComponent.
    /// </summary>
    void Initialize() override;
    /// <summary>
    /// Updates the component via UpdateEvent.
    /// </summary>
    /// <param name="event">An event dealing with the updating of this component.</param>
    void Update(UpdateEvent * event);
    /// <summary>
    /// Sets up the component from with the given XML Element.
    /// </summary>
    /// <param name="element">The element with the data needed to initialize.</param>
    virtual void InitializeFromXML(const MistThread::IO::XML::XMLElement & element) override;
    /// <summary>
    /// Populates the given XML Element with data for saving.
    /// </summary>
    /// <param name="element">The element to fill with data.</param>
    virtual void PopulateXML(MistThread::IO::XML::XMLElement & element) const override;

    //Variables
    MistThread::Core::Vector2 Velocity; //The publicly accessable velocity of the object, after all variables have been applied.

  private:
    MistThread::Core::GameObjects::Components::TransformComponent* transform_; //Reference to the owner's transform.
    MistThread::Core::Vector2 randomVel_;                                      //The generated random velocity.

    //Parsed
    MistThread::Core::Vector2 requestedVel_; //The velocity requested by the user.
    double randomizationPercentage_;         //From 0.0 to 1.0, representing the percentage randomVel_ is factored into requestedVel_.
    double speed_;                           //The speed of the particle in engine units pre-variation.
    double speedVariation_;                  //The provided variation from the original speed provided.
};