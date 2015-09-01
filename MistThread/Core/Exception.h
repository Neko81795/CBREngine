#pragma once
#include <exception>
#include <string>

namespace MistThread
{
  namespace Core
  {
    class Exception : public std::exception
    {
    public:
      std::string Trace;
      Exception *InnerException;

      Exception(const char *message = "", Exception *innerException = NULL);
      virtual ~Exception();
    };
  }
}
