#include "ForceComponent.h"



ForceComponent::ForceComponent(MistThread::Core::GameObjects::GameObjectBase* owner) : Component(owner, "Transform"), randomVel_(Random::RandRange(-1, 1), Random::RandRange(-1, 1))
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
  if (speedVariation_ < speed_)
    speed_ = speed_ + Random::RandRange(-speedVariation_, speedVariation_);
  if (randomizationPercentage_ > 1)
    randomizationPercentage_ = 1;
  else if (randomizationPercentage_ < 0)
    randomizationPercentage_ = 0;

  //Calculate velocity.
  Velocity.X = requestedVel_.X * (1.0 - randomizationPercentage_) + randomVel_.X * randomizationPercentage_;
  Velocity.Y = requestedVel_.Y * (1.0 - randomizationPercentage_) + randomVel_.Y * randomizationPercentage_;
  Velocity = Velocity.Normalize();
  Velocity *= speed_;
}


void ForceComponent::Update(UpdateEvent * event)
{
  transform_->Position += Velocity;
}


/// <summary>
/// Sets up the component from with the given XML Element
/// </summary>
/// <param name="element">the element with the data needed to initialize</param>
void ForceComponent::InitializeFromXML(const MistThread::IO::XML::XMLElement & element)
{
  Component::InitializeFromXML(element);

  std::stringstream str(element.GetAttributeByName("Velocity").Value);
  str >> requestedVel_;

  str = std::stringstream();
  str << element.GetAttributeByName("RandomizationPercentage").Value;
  str >> randomizationPercentage_;

  str = std::stringstream();
  str << element.GetAttributeByName("Speed").Value;
  str >> speed_;

  str = std::stringstream();
  str << element.GetAttributeByName("SpeedVariation").Value;
  str >> speedVariation_;
}


/// <summary>
/// Populates the given XML Element with data for saving
/// </summary>
/// <param name="element">the element to fill with data</param>
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
