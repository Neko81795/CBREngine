#include "ContentManager.h"
#include "../Graphics/Bitmap.h"
#include "../Core/Game.h"
#include "../Graphics/Engines/GraphicsEngineCore.h"

namespace MistThread
{
  namespace Utilities
  {
    template<typename T>
    ContentManager::ContentInfo<T>::ContentInfo(T * content, const std::string &path, bool persistant)
    {
      Content = content;
      Path = path;
      Persistant = persistant;
    }

    template<typename T>
    ContentManager::ContentInfo<T>::~ContentInfo()
    {
      delete Content;
      Content = NULL;
    }

    std::map<std::string, ContentManager::ContentInfo<Graphics::Bitmap> *> ContentManager::LoadedBitmaps;
    std::string ContentManager::RootFolder;

    Graphics::Bitmap & ContentManager::LoadBitmapFile(const std::string &path)
    {
      auto &content = LoadedBitmaps[path];

      if (content)
        return *content->Content;

      content = new ContentInfo<Graphics::Bitmap>(new Graphics::Bitmap(*Core::Game::CurrentGame->Graphics), path);

      Core::Game::CurrentGame->Graphics->LoadBitmapFromFile(RootFolder + path, *content->Content);
      
      return *content->Content;
    }
  }
}
