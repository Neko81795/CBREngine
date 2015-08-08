#include "SoundPulseComponent.h"



SoundPulseComponent::SoundPulseComponent(MistThread::Core::GameObjects::GameObjectBase* owner) : Component(owner, "Transform Draw")
{
  Name = "SoundPulse";
}


void SoundPulseComponent::Initialize()
{
  //Figure out what the pTransform and pDraw are.
  pTransform_ = static_cast<MistThread::Core::GameObjects::Components::TransformComponent*>(Owner.GetComponentByName("Transform"));
  pDraw_ = static_cast<MistThread::Core::GameObjects::Components::DrawComponent*>(Owner.GetComponentByName("Draw"));

  //Attach the update event to this component.
  Space.AttachEventHandler(
    "Update",
    [](void * obj, Event* event) { static_cast<SoundPulseComponent *>(obj)->Update(static_cast<UpdateEvent *>(event)); },
    this);
}


void SoundPulseComponent::Update(UpdateEvent * event)
{
  if (sound_.IsPlaying())
  {
    //Get the spectrum of the current sound object, and set the alpha accordingly.
    MistThread::Audio::Spectrum s = sound_.GetSpectrum(MistThread::Audio::SPECTRUM_64, FMOD_DSP_FFT_WINDOW_BLACKMAN);
    s[2] *= 10;
    pDraw_->Color.SetA(s[2]);
  }
}

void SoundPulseComponent::SetSound(std::string s)
{
  sound_.Play(s);
}

SoundPulseComponent::~SoundPulseComponent()
{ }
