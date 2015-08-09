#include "SinXComponent.h"
#include <sstream>

void SinXComponent::Update(UpdateEvent * event)
{
  Transform->Position.X = std::sinf(static_cast<float>(event->GameTime.TotalTime) * (2 * 3.1415926535f / Period)) * Scale + Offset;
}

void SinXComponent::Initialize()
{
  Transform = static_cast<MistThread::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));

  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<SinXComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}

void SinXComponent::InitializeFromXML(const MistThread::IO::XML::XMLElement & element)
{
  Component::InitializeFromXML(element);

  std::stringstream str(element.GetAttributeByName("Period").Value);
  str >> Period;
  str = std::stringstream(); //reset the stream

  str << element.GetAttributeByName("Scale").Value;
  str >> Scale;
  str = std::stringstream(); //reset the stream

  str << element.GetAttributeByName("Offset").Value;
  str >> Offset;
}

void SinXComponent::PopulateXML(MistThread::IO::XML::XMLElement & element) const
{
  Component::PopulateXML(element);

  std::stringstream str;
  str << Period;
  element.SetAttribute("Period", str.str());

  str = std::stringstream();
  str << Scale;
  element.SetAttribute("Scale", str.str());

  str = std::stringstream();
  str << Offset;
  element.SetAttribute("Offset", str.str());
}

SinXComponent::SinXComponent(MistThread::Core::GameObjects::GameObjectBase * owner) : Component(owner, "Transform")
{
  Name = "SinX";
}
