#pragma once

#include <string>
#include "../Core/Delegate.h"

#if WIN32
#pragma comment(lib, "d2d1")
#pragma comment(lib, "dwrite")
#include <wrl.h>
#pragma warning(disable: 4838) //disable conversion warnings
#pragma warning(disable: 4458) //disable hiding class members
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite_2.h>
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
      class LimitedGraphicsEngineCore; //forward Declaration
    }
    class GraphicsEvent; //forward Declaration

    class TextFormat
    {
      friend Engines::LimitedGraphicsEngineCore;
      friend void DevRecreate(void * obj, GraphicsEvent & evnt);
    private:
#if WIN32
      friend Engines::DirectXGraphicsEngine;
      template<typename T>
      using ComPtr = Microsoft::WRL::ComPtr<T>;
      ComPtr<IDWriteTextFormat> Format_;

      void UpdateFormat(Engines::LimitedGraphicsEngineCore * eng = NULL);
#endif
      std::string Font;
      float Size;
      Core::Delegate<GraphicsEvent &> DeviceRecreatedCallback;

    public:
      void SetFont(const std::string &fontName);
      void SetSize(float size);

      std::string GetFont() const;
      float GetSize() const;

      TextFormat& operator=(const TextFormat& rhs);
      friend std::istream &operator>>(std::istream &stream, TextFormat& color);
      friend std::ostream &operator<<(std::ostream &stream, const TextFormat& color);

    private:
      /// <summary>
      /// creates a text format using the graphics given
      /// </summary>
      /// <param name="graphics">the graphics to use</param>
      /// <param name="fontName">the name of the font to use</param>
      /// <param name="size">the size in point that the font should be</param>
      TextFormat(Engines::LimitedGraphicsEngineCore *graphics, const std::string &fontName, float size);
    public:
      /// <summary>
      /// creates a default text format
      /// </summary>
      TextFormat();
      /// <summary>
      /// creates a text format using the graphics of the current game
      /// </summary>
      /// <param name="fontName">the name of the font to use</param>
      /// <param name="size">the size in point that the font should be</param>
      TextFormat(const std::string &fontName, float size);
      TextFormat(const TextFormat & other);
      ~TextFormat();
    };
  }
}
