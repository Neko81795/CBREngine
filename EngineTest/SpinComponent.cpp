#include "SpinComponent.h"
#include <sstream>


void SpinComponent::Update(UpdateEvent *)
{
  Transform->Rotation += RotationSpeed;
  RotationSpeed += Acceleration;
}

void SpinComponent::Initialize()
{
  Transform = static_cast<MistThread::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));

  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<SpinComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}

void SpinComponent::InitializeFromXML(const MistThread::IO::XML::XMLElement & element)
{
  Component::InitializeFromXML(element);

  std::stringstream str(element.GetAttributeByName("Rotation").Value);
  str >> RotationSpeed;
  str = std::stringstream(); //reset the stream

  str << element.GetAttributeByName("Acceleration").Value;
  str >> Acceleration;
}

void SpinComponent::PopulateXML(MistThread::IO::XML::XMLElement & element) const
{
  Component::PopulateXML(element);

  std::stringstream str;
  str << RotationSpeed;
  element.SetAttribute("Rotation", str.str());

  str = std::stringstream(); //reset the stream
  str << Acceleration;
  element.SetAttribute("Acceleration", str.str());
}

SpinComponent::SpinComponent(MistThread::Core::GameObjects::GameObjectBase * owner) : Component(owner, "Transform")
{
  Name = "Spin";
}
