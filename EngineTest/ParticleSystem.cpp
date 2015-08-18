#include "ParticleSystem.h"
#include "ParticleData.h"
#include <sstream>
#include <random>
#include <chrono>


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
        for (int i = 0; i < maxGeneratedPerFrame_; ++i)
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
          for (int i = 0; i < maxGeneratedPerFrame_; ++i)
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
  //New object
  MistThread::Core::GameObjects::GameObject &newObj = Space.CreateObjectAt(transform_->Position, transform_->GetZLayer());
  newObj.InitializeFromXML(elementXML_);

  //random
  std::uniform_real_distribution<double> distribution(-lifeVariation_, lifeVariation_);
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::default_random_engine generator(seed);

  ParticleData* part = newObj.AddComponentByName<ParticleData>("ParticleData");
  
  //Handle Life
  if (lifeVariation_ < life_)
    part->Life = life_ + distribution(generator);
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
  //Attach the update event to all the objects.
  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<ParticleSystem *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);

  transform_ = static_cast<MistThread::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));
}

void ParticleSystem::InitializeFromXML(const MistThread::IO::XML::XMLElement & element)
{
  Component::InitializeFromXML(element);
  elementXML_ = element.GetElementByName("GameObjectParticle");

  std::stringstream str(element.GetAttributeByName("MaxParticles").Value);
  str >> maxParticles_;
  str = std::stringstream();

  str << element.GetAttributeByName("MaxGeneratedPerFrame").Value;
  str >> maxGeneratedPerFrame_;
  str = std::stringstream();

  str << element.GetAttributeByName("GenerationRadius").Value;
  str >> generationRadius_;
  str = std::stringstream();

  str << element.GetAttributeByName("Life").Value;
  str >> life_;
  str = std::stringstream();

  str << element.GetAttributeByName("LifeVariation").Value;
  str >> lifeVariation_;
  str = std::stringstream();
  
  str << element.GetAttributeByName("EmissionDelay").Value;
  str >> emissionDelay_;
  str = std::stringstream();

  str << element.GetAttributeByName("Repeating").Value;
  str >> repeating_;
  str = std::stringstream();

  str << element.GetAttributeByName("GeneratedImmediately").Value;
  str >> generateImmediately_;
}

void ParticleSystem::PopulateXML(MistThread::IO::XML::XMLElement & element) const
{
  Component::PopulateXML(element);

  std::stringstream str;
  str << maxParticles_;
  element.SetAttribute("MaxParticles", str.str());

  str = std::stringstream();
  str << maxGeneratedPerFrame_;
  element.SetAttribute("MaxGeneratedPerFrame", str.str());

  str = std::stringstream();
  str << generationRadius_;
  element.SetAttribute("GenerationRadius", str.str());

  str = std::stringstream();
  str << life_;
  element.SetAttribute("Life", str.str());

  str = std::stringstream();
  str << lifeVariation_;
  element.SetAttribute("LifeVariation", str.str());

  str = std::stringstream();
  str << emissionDelay_;
  element.SetAttribute("EmissionDelay", str.str());

  str = std::stringstream();
  str << repeating_;
  element.SetAttribute("Repeating", str.str());

  str = std::stringstream();
  str << generateImmediately_;
  element.SetAttribute("GeneratedImmediately", str.str());

  element.Elements.push_back(elementXML_);
}
