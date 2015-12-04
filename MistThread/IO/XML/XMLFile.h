#pragma once
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include "XMLElement.h"

namespace MistThread
{
  namespace IO
  {
    namespace XML
    {
      class XMLFile
      {
      public:
        std::vector<XMLElement> Elements;
        std::stack<XMLElement *> ActiveElements;
        XMLFile(const std::string &path);
        ~XMLFile();
      };
    }
  }
}
