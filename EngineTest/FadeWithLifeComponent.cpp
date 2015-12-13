#include "FadeWithLifeComponent.h"



FadeWithLifeComponent::FadeWithLifeComponent(MistThread::Core::GameObjects::GameObjectBase* owner) : Component(owner, "Transform ParticleData")
{
  Name = "FadeWithLife";
}


void FadeWithLifeComponent::Initialize()
{
  //Find dependancies.
  pParticleData_ = static_cast<ParticleDataComponent *>(Owner.GetComponentByName("ParticleData"));
  pDrawBitmap_ = static_cast<MistThread::Core::GameObjects::Components::DrawBitmapComponent*>(Owner.GetComponentByName("DrawBitmap"));

  //Attach events.
  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<FadeWithLifeComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}


void FadeWithLifeComponent::Update(UpdateEvent * event)
{

}


void FadeWithLifeComponent::DeSerialize(const MistThread::IO::XML::XMLElement & element)
{
  Component::DeSerialize(element);
}


void FadeWithLifeComponent::Serialize(MistThread::IO::XML::XMLElement & element) const
{
  Component::Serialize(element);
}
