#pragma once

#include <sstream>

namespace MistThread
{
  namespace Core
  {
    template<typename T>
    void CreateException__(std::ostream& stream, const T& arg0)
    {
      stream << arg0;
    }

    inline void CreateException_(std::ostream&) {}

    template<typename T, typename... Args>
    void CreateException_(std::ostream& stream, const T& arg0, const Args&... args)
    {
      CreateException__(stream, arg0);
      CreateException_(stream, args...);
    }

    template<typename exceptionType, typename T, typename... Args>
    exceptionType CreateException(const T& arg0, const Args&... args)
    {
      std::stringstream str;
      str << arg0;
      CreateException_(str, args...);
      return exceptionType(str.str().c_str());
    }
  }
}