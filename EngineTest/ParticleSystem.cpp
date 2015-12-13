#include "ParticleSystem.h"
#include "ParticleDataComponent.h"
#include <sstream>
#include <random>


void ParticleSystem::Update(UpdateEvent * event)
{
  //If we have waited long enough...
  if (event->GameTime.TotalTime - lastGenerationTime_ >= emissionDelay_)
    //If we have not spawned the max particles in this system...
    if (activeParticles_ < maxParticles_)
    {
      //If we are repeating...
      if (repeating_)
      {
        //Attempt to generate for the maximum number.
        for (unsigned int i = 0; i < maxGeneratedPerFrame_; ++i)
          //If we can still generate...
          if (activeParticles_ < maxParticles_)
            CreateParticle();
          else
            break;
      }
      else
      {
        //If we are not repeating, just generate.
        if (totalParticlesProduced_ < maxParticles_)
        {
          //Attempt to generate for max num.
          for (unsigned int i = 0; i < maxGeneratedPerFrame_; ++i)
            //If we can still generate...
            if (activeParticles_ < maxParticles_)
              CreateParticle();
            else
              break;
        }
      }

      lastGenerationTime_ = event->GameTime.TotalTime;
    }
}

void ParticleSystem::CreateParticle()
{
  //New object.
  MistThread::Core::GameObjects::GameObject &newObj = Space.CreateObjectAt(transform_->Position, transform_->GetZLayer());
  newObj.DeSerialize(elementXML_);
  newObj.Initialize();

  ParticleDataComponent* part = newObj.AddComponentByName<ParticleDataComponent>("ParticleData");
  part->Initialize();
  newObj.AttachEventHandler(
    "ObjectDestroyed",
    [](void * obj, Event* event) { static_cast<ParticleSystem *>(obj)->MonitorParticles(static_cast<ObjectDestroyedEvent *>(event)); },
    this);
  //Handle Life.
  if (lifeVariation_ < life_)
    part->Life = life_ + Random::RandRange(-lifeVariation_, lifeVariation_);
  else
    part->Life = life_;


  ++totalParticlesProduced_;
  ++activeParticles_;
}


ParticleSystem::ParticleSystem(MistThread::Core::GameObjects::GameObjectBase* owner) : Component(owner, "Transform"), elementXML_("ParticleSystem")
{
  Name = "ParticleSystem";
}


void ParticleSystem::Initialize()
{
  transform_ = static_cast<MistThread::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));

  //Attach the update event to all the objects.
  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<ParticleSystem *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}


/// <summary>
/// Sets up the component from with the given XML Element
/// </summary>
/// <param name="element">the element with the data needed to initialize</param>
void ParticleSystem::DeSerialize(const MistThread::IO::XML::XMLElement & element)
{
  Component::DeSerialize(element);
  elementXML_ = *element.GetElementByName("GameObjectParticle");

  maxParticles_ = element.GetAttributeValueByName<unsigned int>("MaxParticles", 10);
  maxGeneratedPerFrame_ = element.GetAttributeValueByName<unsigned int>("MaxGeneratedPerFrame", 1);
  generationRadius_ = element.GetAttributeValueByName("GenerationRadius", 0.0);
  life_ = element.GetAttributeValueByName("Life", 60000.0);
  lifeVariation_ = element.GetAttributeValueByName<double>("LifeVariation");
  emissionDelay_ = element.GetAttributeValueByName("EmissionDelay", 1000.0);
  repeating_ = element.GetAttributeValueByName("Repeating", true);
  generateImmediately_ = element.GetAttributeValueByName("GeneratedImmediately", true);
}


void ParticleSystem::Serialize(MistThread::IO::XML::XMLElement & element) const
{
  Component::Serialize(element);

  element.SetAttribute("MaxParticles", maxParticles_);
  element.SetAttribute("MaxGeneratedPerFrame", maxGeneratedPerFrame_);
  element.SetAttribute("GenerationRadius", generationRadius_);
  element.SetAttribute("Life", life_);
  element.SetAttribute("LifeVariation", lifeVariation_);
  element.SetAttribute("EmissionDelay", emissionDelay_);
  element.SetAttribute("Repeating", repeating_);
  element.SetAttribute("GeneratedImmediately", generateImmediately_);

  element.Elements.push_back(elementXML_);
}


void ParticleSystem::MonitorParticles(ObjectDestroyedEvent * event)
{
  --activeParticles_;
}
