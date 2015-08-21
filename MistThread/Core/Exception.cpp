#include "Exception.h"
#ifdef WIN32
#pragma warning(disable:4091)
#include <Windows.h>
#include <DbgHelp.h>

#pragma comment(lib, "DbgHelp")
#pragma warning(default:4091)
#else
#include <execinfo.h>
#endif

namespace MistThread
{
  namespace Core
  {
    Exception::Exception(const char *message, Exception *innerException) : std::exception(message)
    {
      InnerException = innerException;
#ifdef WIN32
      unsigned short numFrames;
      void *stack[100];
      HANDLE process;
      //this is a pain in the ass. who designed this
      SYMBOL_INFO *symbol = (SYMBOL_INFO *)calloc(sizeof(SYMBOL_INFO) + 256 * sizeof(char), 1);
      symbol->MaxNameLen = 255;
      symbol->SizeOfStruct = sizeof(SYMBOL_INFO);


      process = GetCurrentProcess();
      SymInitialize(process, NULL, true);

      numFrames = CaptureStackBackTrace(1, 100, stack, NULL);

      for(int i = 0; i < numFrames; i++)
      {
        SymFromAddr(process, DWORD64(stack[i]), 0, symbol);

        Trace += "at: ";
        Trace += symbol->Name;
        Trace += "\n\r";

      }
      
      free(symbol);
#endif
    }


    Exception::~Exception()
    {

    }
  }
}
