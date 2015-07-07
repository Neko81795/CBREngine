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

    TextFormat::TextFormat(Engines::LimitedGraphicsEngineCore *graphics, const std::string &fontName, float size)
    {
      Font = fontName;
      Size = size;

      graphics->DeviceRecreated += Core::Delegate<GraphicsEvent &>([](void * obj, GraphicsEvent & evnt)
      {
        reinterpret_cast<TextFormat *>(obj)->UpdateFormat(evnt.Graphics);
      }, this);

#if WIN32
      UpdateFormat(graphics);
#endif
    }

    TextFormat::TextFormat(const std::string &fontName, float size)
    {
      Font = fontName;
      Size = size;

      Core::Game::CurrentGame->Graphics->DeviceRecreated += Core::Delegate<GraphicsEvent &>([](void * obj, GraphicsEvent & evnt)
      {
        reinterpret_cast<TextFormat *>(obj)->UpdateFormat(evnt.Graphics);
      }, this);

#if WIN32
      UpdateFormat();
#endif
    }

    TextFormat::TextFormat(const TextFormat & other)
    {
      Font = other.Font;
      Size = other.Size;

      Core::Game::CurrentGame->Graphics->DeviceRecreated += Core::Delegate<GraphicsEvent &>([](void * obj, GraphicsEvent & evnt)
      {
        reinterpret_cast<TextFormat *>(obj)->UpdateFormat(evnt.Graphics);
      }, this);

#if WIN32
      UpdateFormat();
#endif
    }

    TextFormat::~TextFormat()
    {
      Core::Game::CurrentGame->Graphics->DeviceRecreated -= Core::Delegate<GraphicsEvent &>([](void * obj, GraphicsEvent & evnt)
      {
        reinterpret_cast<TextFormat *>(obj)->UpdateFormat(evnt.Graphics);
      }, this);
    }
  }
}
