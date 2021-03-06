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

void SinXComponent::DeSerialize(const MistThread::IO::XML::XMLElement & element)
{
  Component::DeSerialize(element);

  Period = element.GetAttributeValueByName("Period", 1.0f);
  Scale = element.GetAttributeValueByName("Scale", 1.0f);
  Offset = element.GetAttributeValueByName<float>("Offset");
}

void SinXComponent::Serialize(MistThread::IO::XML::XMLElement & element) const
{
  Component::Serialize(element);

  element.SetAttribute("Period", Period);
  element.SetAttribute("Scale", Scale);
  element.SetAttribute("Offset", Offset);
}

SinXComponent::SinXComponent(MistThread::Core::GameObjects::GameObjectBase * owner) : Component(owner, "Transform")
{
  Name = "SinX";
}
