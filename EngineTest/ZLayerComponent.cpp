#include "ZLayerComponent.h"



void ZLayerComponent::Update(UpdateEvent * event)
{
  Transform->SetZLayer(std::sinf(static_cast<float>(event->GameTime.TotalTime * 0.24)) * 20);
}

void ZLayerComponent::Initialize()
{
  Transform = static_cast<MistThread::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));

  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<ZLayerComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}

ZLayerComponent::ZLayerComponent(MistThread::Core::GameObjects::GameObjectBase * owner) : Component(owner, "Transform")
{
  Name = "ZLayer";
}
