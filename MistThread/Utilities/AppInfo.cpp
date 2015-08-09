#include "AppInfo.h"

#ifdef WIN32
#include <WinSock2.h>
#include <direct.h>

#define GETCURWORKDIR _getcwd

#pragma comment(lib, "Ws2_32")
#endif

#define MAXPATHLENGTH 2048

namespace MistThread
{
  namespace Utilities
  {
#ifdef WIN32
    std::string AppInfo::GetHostName()
    {
      char buffer[256]{};
      gethostname(buffer, 256);
      return std::string(buffer);
    }

    std::string AppInfo::GetCurrentWorkingDirectory()
    {
      char buffer[MAXPATHLENGTH]{};
      GETCURWORKDIR(buffer, sizeof(buffer));
      return std::string(buffer) + '\\';
    }

    AppInfo::AppInfo()
    {
      WSADATA wsaData;
      //get version 2.2
      WSAStartup(MAKEWORD(2,2), &wsaData);
    }
#endif
  }
}
