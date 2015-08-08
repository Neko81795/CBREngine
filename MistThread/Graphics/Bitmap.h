#pragma once
#include "../Core/Size2.h"
#include "../Core/Delegate.h"

#if WIN32
#include <wrl.h>
#include <wincodec.h>
#pragma warning(disable: 4838) //disable conversion warnings
#pragma warning(disable: 4458) //disable hiding class members
#include <d2d1.h>
#pragma warning(default: 4458) //enable hiding class members
#pragma warning(default: 4838) //enable conversion warnings

#endif

namespace MistThread
{
  namespace Graphics
  {
    namespace Engines
    {
#if WIN32
      class DirectXGraphicsEngine; //forward Declaration
#endif
      class GraphicsEngineCore; //forward Declaration
    }
    class GraphicsEvent; //forward Declaration

    class Bitmap
    {
      
      //variables
#if WIN32
      template <typename T>
      using ComPtr = Microsoft::WRL::ComPtr<T>;

      friend class Engines::DirectXGraphicsEngine;
    private:
      Core::Delegate<GraphicsEvent &> *DeviceRecreatedCallback;
      Engines::GraphicsEngineCore *Engine;
      ComPtr<IWICFormatConverter> WICImage;
      ComPtr<ID2D1Bitmap> D2DImage;
#endif
        //methods
    private:
      void Recreate(GraphicsEvent & evnt);
    public:
      Bitmap(Engines::GraphicsEngineCore & engine);
      ~Bitmap();

      Core::Size2 GetSize();
    };
  }
}
