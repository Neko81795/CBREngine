#include "XMLAttribute.h"


namespace MistThread
{
  namespace IO
  {
    namespace XML
    {
      XMLAttribute::XMLAttribute(const std::string &name, const std::string &value)
      {
        Name = name;
        Value = value;
      }


      XMLAttribute::~XMLAttribute()
      {

      }
    }
  }
}
