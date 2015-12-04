#pragma once
#include "../MistThread/Core.h"
#include <sstream>
#include "ParticleDataComponent.h"

using Event = MistThread::Core::Event;
using UpdateEvent = MistThread::Core::GameObjects::Components::UpdateEvent;



struct GatherKeystrokesComponent : public MistThread::Core::GameObjects::Components::Component
{
  //Constructors
  /// <summary>
  /// Constructs the component.
  /// </summary>
  /// <param name="owner">The Object this component is attached to.</param>
  GatherKeystrokesComponent(MistThread::Core::GameObjects::GameObjectBase* owner);
  /// <summary>
  /// Default destructor for the component.
  /// </summary>
  ~GatherKeystrokesComponent() { }

  //Member Functions
  /// <summary>
  /// Initializes the FadeWithLifeComponent.
  /// </summary>
  void Initialize() override;
  /// <summary>
  /// Updates the component via UpdateEvent.
  /// </summary>
  /// <param name="event">An event dealing with the updating of this component.</param>
  void Update(UpdateEvent * event);
  /// <summary>
  /// Sets up the component from with the given XML Element.
  /// </summary>
  /// <param name="element">The element with the data needed to initialize.</param>
  virtual void InitializeFromXML(const MistThread::IO::XML::XMLElement & element) override;
  /// <summary>
  /// Populates the given XML Element with data for saving.
  /// </summary>
  /// <param name="element">The element to fill with data.</param>
  virtual void PopulateXML(MistThread::IO::XML::XMLElement & element) const override;

private:
  std::string lastLine_;                                                        //Pointer to the particle data.
  MistThread::Core::GameObjects::Components::DrawBitmapComponent *pDrawBitmap_; //Pointer to the image we are going to be playing with.
};