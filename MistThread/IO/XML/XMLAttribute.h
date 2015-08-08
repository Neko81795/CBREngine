#pragma once
#include <string>

namespace MistThread
{
  namespace IO
  {
    namespace XML
    {
      class XMLAttribute
      {
      public:
        std::string Name;
        std::string Value;

        XMLAttribute(const std::string &name, const std::string &value = "");
        ~XMLAttribute();
      };
    }
  }
}
