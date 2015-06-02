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

    std::list<ContentManager::ContentInfo<Graphics::Bitmap> *> ContentManager::LoadedBitmaps;
    std::string ContentManager::RootFolder;

    Graphics::Bitmap & ContentManager::LoadBitmapFile(const std::string &path)
    {
      for (auto content : LoadedBitmaps)
      {
        if (content->Path == path)
          return *content->Content;
      }

      LoadedBitmaps.push_back(new ContentInfo<Graphics::Bitmap>(new Graphics::Bitmap(*Core::Game::CurrentGame->Graphics), path));
      auto content = LoadedBitmaps.back();

      Core::Game::CurrentGame->Graphics->LoadBitmapFromFile(RootFolder + path, *content->Content);
      
      return *content->Content;
    }
  }
}
