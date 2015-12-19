#include "GatherKeystrokesComponent.h"
#include "../MistThread/Core/Delegate.h"


static void localKBCall(void *obj, MT_INPUT::KeyboardEvent &e);

void GatherKeystrokesComponent::Initialize()
{
  //Register for update
  OLD_EVENT_ATTACH(Update, GatherKeystrokesComponent);

  //Register for keyboard down event via delegate
  keyboardDel_ = new MT_CORE::Delegate<MT_INPUT::KeyboardEvent &>(localKBCall, this);
  Game.Window->OnKeyDown += keyboardDel_;
}


GatherKeystrokesComponent::~GatherKeystrokesComponent()
{
  Game.Window->OnKeyDown -= keyboardDel_;
  delete keyboardDel_;
}


void GatherKeystrokesComponent::Update(UpdateEvent *e)
{
  std::vector<Key> keysDown = Keyboard::Current.GetAllKeysDown();
}


void GatherKeystrokesComponent::GetKBVals(MT_INPUT::KeyboardEvent &e)
{
  std::lock_guard<std::mutex> lock(m_lastLine_);
  lastLine_ << e.Key
}


//Local function designed to call corresponding member function.
static void localKBCall(void *obj, MT_INPUT::KeyboardEvent &e)
{
  static_cast<GatherKeystrokesComponent *>(obj)->GetKBVals(e);
}


