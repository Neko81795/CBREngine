#pragma once
#include "../MistThread/Core.h"
#include <sstream>
#include "Random.h"

using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;



struct ForceComponent : public MistThread::Core::GameObjects::Components::Component
{
    //Constructors
    ForceComponent(MistThread::Core::GameObjects::GameObjectBase* owner);
    ~ForceComponent() { }

    //Member Functions
    void Initialize() override;
    void Update(UpdateEvent * event);

    virtual void InitializeFromXML(const MistThread::IO::XML::XMLElement & element) override;
    virtual void PopulateXML(MistThread::IO::XML::XMLElement & element) const override;

    //Variables
    MistThread::Core::Vector2 Velocity;
  private:
    MistThread::Core::GameObjects::Components::TransformComponent* transform_;
    MistThread::Core::Vector2 randomVel_;

    //Parsed
    MistThread::Core::Vector2 requestedVel_;
    double randomizationPercentage_;
    double speed_;
    double speedVariation_;
};