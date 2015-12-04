#include "ForceComponent.h"



ForceComponent::ForceComponent(MistThread::Core::GameObjects::GameObjectBase* owner) : Component(owner, "Transform"), randomVel_(static_cast<float>(Random::RandRange(-1, 1)), static_cast<float>(Random::RandRange(-1, 1)))
{
  Name = "Force";
}


void ForceComponent::Initialize()
{
  //Find dependancies.
  transform_ = static_cast<MistThread::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));

  //Attach events.
  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<ForceComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);

  //Cap relevant values
  double tempSpeed = speed_;
  if (speedVariation_ < speed_)
    tempSpeed = speed_ + Random::RandRange(-speedVariation_, speedVariation_);
  if (randomizationPercentage_ > 1)
    randomizationPercentage_ = 1;
  else if (randomizationPercentage_ < 0)
    randomizationPercentage_ = 0;

  //Calculate velocity.
  Velocity.X = static_cast<float>(requestedVel_.X * (1.0 - randomizationPercentage_) + randomVel_.X * randomizationPercentage_);
  Velocity.Y = static_cast<float>(requestedVel_.Y * (1.0 - randomizationPercentage_) + randomVel_.Y * randomizationPercentage_);
  Velocity = Velocity.Normalize();
  Velocity *= static_cast<float>(tempSpeed);
}


void ForceComponent::Update(UpdateEvent * event)
{
  transform_->Position += Velocity;
}


void ForceComponent::InitializeFromXML(const MistThread::IO::XML::XMLElement & element)
{
  Component::InitializeFromXML(element);

  requestedVel_ = element.GetAttributeValueByName<MistThread::Core::Vector2>("Velocity");
  randomizationPercentage_ = element.GetAttributeValueByName<double>("RandomizationPercentage");
  speed_ = element.GetAttributeValueByName<double>("Speed");
  speedVariation_ = element.GetAttributeValueByName<double>("SpeedVariation");
}


void ForceComponent::PopulateXML(MistThread::IO::XML::XMLElement & element) const
{
  Component::PopulateXML(element);

  std::stringstream str;
  str << requestedVel_;
  element.SetAttribute("Velocity", str.str());

  str = std::stringstream();
  str << randomizationPercentage_;
  element.SetAttribute("RandomizationPercentage", str.str());

  str = std::stringstream();
  str << speed_;
  element.SetAttribute("Speed", str.str());

  str = std::stringstream();
  str << speedVariation_;
  element.SetAttribute("SpeedVariation", str.str());
}
