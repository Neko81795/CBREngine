#pragma once

#include "../MistThread/Core.h"
#include "../MistThread/Audio/Spectrum.h"
#include "../MistThread/Audio/Sound.h"
#include <string>

using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;



class SoundPulseComponent : public MistThread::Core::GameObjects::Components::Component
{
  public:
    /// <summary>
    /// Retrieves the owner of the component.
    /// </summary>
    /// <param name="owner">The owner of this component.</param>
    SoundPulseComponent(MistThread::Core::GameObjects::GameObjectBase* owner);
    ~SoundPulseComponent();
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
    std::string soundName_;
    MistThread::Audio::Sound sound_;
    float volume_;
    bool looping_;
    MistThread::Core::GameObjects::Components::TransformComponent *pTransform_;
    MistThread::Core::GameObjects::Components::DrawComponent *pDraw_;
};

