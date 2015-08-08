#include "TextFormat.h"
#include "Engines/GraphicsEngineCore.h"
#include "GraphicsEvents.h"
#include "../Core/Game.h"


namespace MistThread
{
  namespace Graphics
  {
    void TextFormat::UpdateFormat(Engines::LimitedGraphicsEngineCore * eng)
    {
      Engines::LimitedGraphicsEngineCore * graphics = eng ? eng : Core::Game::CurrentGame->Graphics;

      graphics->CreateTextFormat(Font, Size, *this);
    }

    void TextFormat::SetFont(const std::string &fontName)
    {
      Font = fontName;
#if WIN32
      UpdateFormat();
#endif
    }

    void TextFormat::SetSize(float size)
    {
      Size = size;
#if WIN32
      UpdateFormat();
#endif
    }

    std::string TextFormat::GetFont() const
    {
      return Font;
    }

    float TextFormat::GetSize() const
    {
      return Size;
    }

    std::istream &operator>>(std::istream &stream, TextFormat& font)
    {
      stream >> font.Size;
      //,
      stream.get();
      stream >> font.Font;

      font.SetSize(font.Size);
      font.SetFont(font.Font);

      return stream;
    }

    std::ostream &operator<<(std::ostream &stream, const TextFormat& font)
    {
      stream << font.Size << "," << font.Font;
      return stream;
    }

    TextFormat::TextFormat(Engines::LimitedGraphicsEngineCore *graphics, const std::string &fontName, float size) : DeviceRecreatedCallback(NULL,NULL)
    {
      Font = fontName;
      Size = size;

      DeviceRecreatedCallback = Core::Delegate<GraphicsEvent &>([](void * obj, GraphicsEvent & evnt)
      {
        reinterpret_cast<TextFormat *>(obj)->UpdateFormat(evnt.Graphics);
      }, this);
      graphics->DeviceRecreated += &DeviceRecreatedCallback;

#if WIN32
      UpdateFormat(graphics);
#endif
    }

    TextFormat::TextFormat(const std::string &fontName, float size) : DeviceRecreatedCallback(NULL, NULL)
    {
      Font = fontName;
      Size = size;

      DeviceRecreatedCallback = Core::Delegate<GraphicsEvent &>([](void * obj, GraphicsEvent & evnt)
      {
        reinterpret_cast<TextFormat *>(obj)->UpdateFormat(evnt.Graphics);
      }, this);

      Core::Game::CurrentGame->Graphics->DeviceRecreated += &DeviceRecreatedCallback;

#if WIN32
      UpdateFormat();
#endif
    }

    TextFormat::TextFormat(const TextFormat & other) : DeviceRecreatedCallback(NULL, NULL)
    {
      Font = other.Font;
      Size = other.Size;



      DeviceRecreatedCallback = Core::Delegate<GraphicsEvent &>([](void * obj, GraphicsEvent & evnt)
      {
        reinterpret_cast<TextFormat *>(obj)->UpdateFormat(evnt.Graphics);
      }, this);

      Core::Game::CurrentGame->Graphics->DeviceRecreated += &DeviceRecreatedCallback;

#if WIN32
      UpdateFormat();
#endif
    }

    TextFormat::~TextFormat()
    {
      Core::Game::CurrentGame->Graphics->DeviceRecreated -= &DeviceRecreatedCallback;
    }
  }
}
