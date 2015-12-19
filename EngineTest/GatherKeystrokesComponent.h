#pragma once
#include "../MistThread/Core.h"
#include "Abbreviations.h"
#include <sstream>
#include <vector>
#include <mutex>


struct GatherKeystrokesComponent : public MT_COMP::Component
{
  //Constructors
  /// <summary>
  /// Constructs the component.
  /// </summary>
  /// <param name="owner">The Object this component is attached to.</param>
  GatherKeystrokesComponent(MT_OBJ::GameObjectBase* owner) : Component(owner) { Name = "GatherKeystrokes"; }
  /// <summary>
  /// Default destructor for the component.
  /// </summary>
  ~GatherKeystrokesComponent();

  //Member Functions
  /// <summary>
  /// Initializes component.
  /// </summary>
  void Initialize() override;
  /// <summary>
  /// Updates the component via UpdateEvent.
  /// </summary>
  /// <param name="event">An event dealing with the updating of this component.</param>
  void Update(UpdateEvent * event);

  void GetKBVals(MT_INPUT::KeyboardEvent &e);


  /// <summary>
  /// Sets up the component from with the given XML Element.
  /// </summary>
  /// <param name="element">The element with the data needed to initialize.</param>
  virtual void DeSerialize(const MistThread::IO::XML::XMLElement & element) override;
  /// <summary>
  /// Populates the given XML Element with data for saving.
  /// </summary>
  /// <param name="element">The element to fill with data.</param>
  virtual void Serialize(MistThread::IO::XML::XMLElement & element) const override;

private:
  //std::string lastLine_;                                                        //Pointer to the particle data.
  std::stringstream lastLine_;
  std::vector<std::string> previousLines_;
  MT_CORE::Delegate<MT_INPUT::KeyboardEvent &> *keyboardDel_;

  // Static mutex for securing registry critical section when multithreading
  // Note: std::lock_guard is exception safe, so use it over mutex.lock
  std::mutex m_lastLine_;
};