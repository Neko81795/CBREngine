#pragma once
#include "../MistThread/Core.h"
#include "../MistThread/Input.h"

//Abbreviated scopes
#define MT_CORE  MistThread::Core
#define MT_INPUT MistThread::Input
#define MT_OBJ   MT_CORE::GameObjects
#define MT_COMP  MT_OBJ::Components

//Prefer 'using' on account of complete type name
using Event       = MT_CORE::Event;
using UpdateEvent = MT_COMP::UpdateEvent;
using Keyboard    = MT_INPUT::Keyboard;
using Key         = MT_INPUT::Key;
using XMLElement  = MistThread::IO::XML::XMLElement;

//Limitation: Local function must be the same name, minus the event at the end.
//This is used as follows:
//
//   void Object::Update(UpdateEvent *e) { ... }
//  
// Note that the name of the function is event, and that we are hooking up to an UpdateEvent.
// To reduce call length, the assumption then is that you are calling a function with the corresponding name
// that exists in your function. This is also used as the identifying name of the event, so pray 
//
// This macro must be called from within the Initialize() function to be used properly.
//
#define OLD_EVENT_ATTACH(name, thisObj)                                                                \
Space.AttachEventHandler(#name,                                                                         \
[](void *obj, Event *event) { static_cast<thisObj *>(obj)->Update(static_cast<name##Event *>(event)); }, \
this)                                                                                                     \
