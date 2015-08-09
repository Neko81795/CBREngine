#pragma once
#include <string>

namespace MistThread
{
  namespace Utilities
  {
    class AppInfo
    {
    public:
      std::string GetHostName();
      std::string GetCurrentWorkingDirectory();

      AppInfo();
    };
  }
}

