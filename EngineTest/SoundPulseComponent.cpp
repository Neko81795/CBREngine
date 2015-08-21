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

  SetSound(soundName_);
}


void SoundPulseComponent::Update(UpdateEvent * event)
{
  if (sound_.IsPlaying())
  {
    //Get the spectrum of the current sound object, and set the alpha accordingly.
    MistThread::Audio::Spectrum s = sound_.GetSpectrum(MistThread::Audio::SPECTRUM_2048, FMOD_DSP_FFT_WINDOW_BLACKMAN);
    float r = 0, g = 0, b = 0;
    static float max1 = 0;
    static float max2 = 0;
    static float max3 = 0;
    for (int i = 0; i < 30; ++i)
    {
        
      if (i < 10)
      {
        r += s[i];
        if(s[i] > max1)
          max1 = s[i];
      }
      else if (i < 20)
      {
        g += s[i];
        if (s[i] > max2)
          max2 = s[i];
      }
      else
      {
        b += s[i];
        if (s[i] > max3)
          max3 = s[i];
      }
    }
    r /= 10;
    g /= 10;
    b /= 10;
    float SCALAR = .999f;
    max1 *= SCALAR;// .985f;
    max2 *= SCALAR;// .985f;
    max3 *= SCALAR;// .985f;
    float maxAvg = (max1 + max2 + max3) / 3;
    static float maxMaxAvg = 0.1f;
    if (maxAvg > .1f)
      maxAvg = .1f;
    //pDraw_->Color.SetA((maxAvg / maxMaxAvg));
    //pDraw_->Color.SetR(r / max1);
    //pDraw_->Color.SetG(g / max2);
    //pDraw_->Color.SetB(b / max3);
    Game.ClearColor.SetA((maxAvg / maxMaxAvg));
    Game.ClearColor.SetR(r / max1);
    Game.ClearColor.SetG(g / max2);
    Game.ClearColor.SetB(b / max3);
  }
}


void SoundPulseComponent::SetSound(std::string s)
{
  if (looping_)
    sound_.Loop(s);
  else
    sound_.Play(s);
  sound_.SetVolume(volume_);
}


SoundPulseComponent::~SoundPulseComponent()
{ }


void SoundPulseComponent::InitializeFromXML(const MistThread::IO::XML::XMLElement & element)
{
  Component::InitializeFromXML(element);

  std::stringstream str(element.GetAttributeByName("Sound").Value);
  str >> soundName_;

  str = std::stringstream();
  str << element.GetAttributeByName("Volume").Value;
  str >> volume_;

  str = std::stringstream();
  str << element.GetAttributeByName("Looping").Value;
  str >> looping_;
}


void SoundPulseComponent::PopulateXML(MistThread::IO::XML::XMLElement & element) const
{
  Component::PopulateXML(element);

  std::stringstream str;
  str << soundName_;
  element.SetAttribute("Sound", str.str());

  str = std::stringstream();
  str << volume_;
  element.SetAttribute("Volume", str.str());

  str = std::stringstream();
  str << volume_;
  element.SetAttribute("Looping", str.str());
}