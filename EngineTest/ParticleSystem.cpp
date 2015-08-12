#include "ParticleSystem.h"
#include "ParticleData.h"
#include <sstream>

void ParticleSystem::Update(UpdateEvent * event)
{
  //if()
}

void ParticleSystem::CreateParticle()
{
  MistThread::Core::GameObjects::GameObject &newObj = Space.CreateObjectAt(transform_->Position, transform_->GetZLayer());
  newObj.InitializeFromXML(elementXML_);
  ParticleData* part = newObj.AddComponentByName<ParticleData>("ParticleData");
  
  //Handle Life
  if (lifeVariation_ < life_)
    part->Life = life_ + ((rand() % lifeVariation_ * 2) - lifeVariation_);
  else
    part->Life = life_;
}

ParticleSystem::ParticleSystem(MistThread::Core::GameObjects::GameObjectBase* owner) : Component(owner, "Transform"), elementXML_("ParticleSystem")
{
  Name = "ParticleSystem";
}

void ParticleSystem::Initialize()
{
  //Attach the update event to all the objects.
  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<ParticleSystem *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}

void ParticleSystem::InitializeFromXML(const MistThread::IO::XML::XMLElement & element)
{
  Component::InitializeFromXML(element);
  elementXML_ = element.GetElementByName("GameObjectParticle");


  std::stringstream str(element.GetAttributeByName("MaxParticles").Value);
  str >> maxParticles_;
  str = std::stringstream();

  str << element.GetAttributeByName("EmissionDelay").Value;
  str >> emissionDelay_;
  str = std::stringstream();

  str << element.GetAttributeByName("Life").Value;
  str >> life_;
  if (life_ < 0)
    life_ = 0;
  str = std::stringstream();

  str << element.GetAttributeByName("LifeVariation").Value;
  str >> lifeVariation_;
  str = std::stringstream();

  str << element.GetAttributeByName("Repeating").Value;
  str >> repeating_;

}

void ParticleSystem::PopulateXML(MistThread::IO::XML::XMLElement & element) const
{
  Component::PopulateXML(element);

  std::stringstream str;
  str << maxParticles_;
  element.SetAttribute("MaxParticles", str.str());

  str = std::stringstream();
  str << life_;
  element.SetAttribute("Life", str.str());

  str = std::stringstream();
  str << lifeVariation_;
  element.SetAttribute("LifeVariation", str.str());

  element.Elements.push_back(elementXML_);
}
