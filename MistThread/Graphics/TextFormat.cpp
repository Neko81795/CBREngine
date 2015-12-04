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
      
      if (Font.empty() && graphics)
      {
        Font = graphics->GetDefaultTextFormat().Font;
        Size = graphics->GetDefaultTextFormat().Size;
      }

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

    TextFormat& TextFormat::operator=(const TextFormat& other)
    {
      if (other.Font.empty())
        return *this;

      Font = other.Font;
      Size = other.Size;

      Core::Game::CurrentGame->Graphics->DeviceRecreated -= &DeviceRecreatedCallback;

      DeviceRecreatedCallback = Core::Delegate<GraphicsEvent &>(DevRecreate, this);

      Core::Game::CurrentGame->Graphics->DeviceRecreated += &DeviceRecreatedCallback;

#if WIN32
      UpdateFormat();
#endif

      return *this;
    }

    std::istream &operator>>(std::istream &stream, TextFormat& font)
    {
      stream >> font.Size;
      //,
      char debug;
      stream.get(debug);
      stream >> font.Font;

      font.SetSize(font.Size);
      font.SetFont(font.Font);

      return stream;
    }

    std::ostream &operator<<(std::ostream &stream, const TextFormat& font)
    {
      stream << font.Size << ", " << font.Font;
      return stream;
    }

    void DevRecreate(void * obj, GraphicsEvent & evnt)
    {
      reinterpret_cast<TextFormat *>(obj)->UpdateFormat(evnt.Graphics);
    }

    TextFormat::TextFormat() : DeviceRecreatedCallback(NULL, NULL)
    {
      if (Core::Game::CurrentGame)
      {
        TextFormat& def = Core::Game::CurrentGame->Graphics->GetDefaultTextFormat();
        Font = def.Font;
        Size = def.Size;

        DeviceRecreatedCallback = Core::Delegate<GraphicsEvent &>(DevRecreate, this);

        Core::Game::CurrentGame->Graphics->DeviceRecreated += &DeviceRecreatedCallback;

#if WIN32
        UpdateFormat();
#endif
      }
      else
      {
        Font = "";
        Size = 0;
      }
    }

    TextFormat::TextFormat(Engines::LimitedGraphicsEngineCore *graphics, const std::string &fontName, float size) : DeviceRecreatedCallback(NULL, NULL)
    {
      Font = fontName;
      Size = size;

      DeviceRecreatedCallback = Core::Delegate<GraphicsEvent &>(DevRecreate, this);

      graphics->DeviceRecreated += &DeviceRecreatedCallback;

#if WIN32
      UpdateFormat(graphics);
#endif
    }

    TextFormat::TextFormat(const std::string &fontName, float size) : DeviceRecreatedCallback(NULL, NULL)
    {
      Font = fontName;
      Size = size;

      DeviceRecreatedCallback = Core::Delegate<GraphicsEvent &>(DevRecreate, this);

      Core::Game::CurrentGame->Graphics->DeviceRecreated += &DeviceRecreatedCallback;

#if WIN32
      UpdateFormat();
#endif
    }

    TextFormat::TextFormat(const TextFormat & other) : DeviceRecreatedCallback(NULL, NULL)
    {
      if (other.Font.empty())
        return;

      Font = other.Font;
      Size = other.Size;



      DeviceRecreatedCallback = Core::Delegate<GraphicsEvent &>(DevRecreate, this);

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
