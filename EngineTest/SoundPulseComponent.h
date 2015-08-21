#pragma once
#include "../MistThread/Core.h"
#include "../MistThread/Audio/Spectrum.h"
#include "../MistThread/Audio/Sound.h"
#include <string>
#include <sstream>

using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;



class SoundPulseComponent : public MistThread::Core::GameObjects::Components::Component
{
  public:
    //Constructors
    /// <summary>
    /// Retrieves the owner of the component.
    /// </summary>
    /// <param name="owner">The owner of this component.</param>
    SoundPulseComponent(MistThread::Core::GameObjects::GameObjectBase* owner);
    ~SoundPulseComponent();

    //Member functions.
    /// <summary>
    /// Updates the sound pulse.
    /// </summary>
    /// <param name="event">The update event </param>
    void Update(UpdateEvent * event);
    /// <summary>
    /// Initializes the component.
    /// </summary>
    void Initialize() override;
    /// <summary>
    /// Sets and plays the sound passed to it.
    /// </summary>
    /// <param name="s"></param>
    void SetSound(std::string s);
    /// <summary>
    /// Sets up the component from with the given XML Element
    /// </summary>
    /// <param name="element">the element with the data needed to initialize</param>
    virtual void InitializeFromXML(const MistThread::IO::XML::XMLElement & element) override;
    /// <summary>
    /// Populates the given XML Element with data for saving
    /// </summary>
    /// <param name="element">the element to fill with data</param>
    virtual void PopulateXML(MistThread::IO::XML::XMLElement & element) const override;

  private:
    //Component Dependencies.
    MistThread::Core::GameObjects::Components::TransformComponent *pTransform_; //A pointer to the transform component.
    MistThread::Core::GameObjects::Components::DrawComponent *pDraw_;           //A pointer to the draw component.

    //Internal Variables.
    MistThread::Audio::Sound sound_; //The sound being used to play and parse data.

    //Parsed Variables.
    std::string soundName_; //The parsed name of the sound.
    float volume_;          //The volume of the sound, from 0.0 to 1.0.
    bool looping_;          //Whether or not the sound is looping.
};

