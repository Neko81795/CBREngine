#include "SpinComponent.h"



void SpinComponent::Update(UpdateEvent *)
{
  Transform->Rotation += (RotationSpeed + RotationVariationAmount);
  RotationSpeed += Acceleration;
}

void SpinComponent::Initialize()
{
  Transform = static_cast<MistThread::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));

  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<SpinComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);

  RotationVariationAmount = static_cast<float>(Random::RandRange(-RotationVariation, RotationVariation));
}

void SpinComponent::DeSerialize(const MistThread::IO::XML::XMLElement & element)
{
  Component::DeSerialize(element);

  RotationSpeed = element.GetAttributeValueByName("Rotation", 1.0f);
  RotationVariation = element.GetAttributeValueByName<float>("RotationVariation");
  Acceleration = element.GetAttributeValueByName<float>("Acceleration");
}

void SpinComponent::Serialize(MistThread::IO::XML::XMLElement & element) const
{
  Component::Serialize(element);

  element.SetAttribute("Rotation", RotationSpeed);
  element.SetAttribute("RotationVariation", RotationVariation);
  element.SetAttribute("Acceleration", Acceleration);
}

SpinComponent::SpinComponent(MistThread::Core::GameObjects::GameObjectBase * owner) : Component(owner, "Transform")
{
  Name = "Spin";
}
