#include "Bitmap.h"
#include "Engines\GraphicsEngineCore.h"
#include "GraphicsEvents.h"

namespace MistThread
{
  namespace Graphics
  {
    void Bitmap::Recreate(GraphicsEvent & evnt)
    {
      evnt.Graphics->ReloadBitmap(*this);
    }

    Bitmap::Bitmap(Engines::GraphicsEngineCore & engine)
    {
      DeviceRecreatedCallback = new Core::Delegate<GraphicsEvent &>([](void * obj, GraphicsEvent & evnt)
      {
        reinterpret_cast<Bitmap *>(obj)->Recreate(evnt);
      }, this);

      engine.DeviceRecreated += DeviceRecreatedCallback;
      Engine = &engine;
    }

    Bitmap::~Bitmap()
    {
      Engine->DeviceRecreated -= DeviceRecreatedCallback;
      delete DeviceRecreatedCallback;
    }

    Core::Size2 Bitmap::GetSize()
    {
#if WIN32
      UINT width, height;
      WICImage->GetSize(&width, &height);
      return Core::Size2((int)width, (int)height);
#else
      return Core::Size2();
#endif
    }
  }
}
