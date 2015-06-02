#pragma once
#include <list>
#include <string>

namespace MistThread
{
  namespace Graphics
  {
    class Bitmap; //forward declaration
  }
  namespace Utilities
  {
    class ContentManager
    {
    private:
      template <typename T>
      class ContentInfo
      {
      public:
        bool Persistant;
        T* Content;
        std::string Path;

      public:
        /// <summary>
        /// Creates a new Content info
        /// </summary>
        /// <param name="content">a pointer to be handled by the class</param>
        /// <param name="persistant">if the content should stay loaded until the game ends</param>
        ContentInfo(T* content, const std::string &path, bool persistant = false);
        ~ContentInfo();
      };

    private:
      static std::list<ContentInfo<Graphics::Bitmap> *> LoadedBitmaps;
    public:
      /// <summary>
      /// the folder where all the content is located
      /// </summary>
      static std::string RootFolder;

    public:
      /// <summary>
      /// Loads a bitmap
      /// </summary>
      /// <param name="path">the path to the bitmap from the root folder</param>
      static Graphics::Bitmap& LoadBitmapFile(const std::string &path);
    };
  }
}
