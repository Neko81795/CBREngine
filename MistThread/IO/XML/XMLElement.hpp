#pragma once

#include <sstream>

namespace MistThread
{
  namespace IO
  {
    namespace XML
    {
      template <typename T>
      T XMLElement::GetAttributeValueByName(const std::string &name) const
      {
        return GetAttributeValueByName(name, T());
      }

      template <>
      inline std::string XMLElement::GetAttributeValueByName<std::string>(const std::string &name, const std::string& def) const
      {
        ConstXMLAttributeHandle hand = GetAttributeByName(name);
        if (hand.Index == -1)
          return def;

        return hand->Value;
      }

      template <typename T>
      T XMLElement::GetAttributeValueByName(const std::string &name, const T& def) const
      {
        ConstXMLAttributeHandle hand = GetAttributeByName(name);
        if (hand.Index == -1)
          return def;
        
        T retval;
        hand >> retval;
        return retval;
      }

      template<>
      inline const XMLAttributeHandle & XMLAttributeHandle::operator>><std::string>(std::string & val) const
      {
        val += Element->Attributes[Index].Value;
        return *this;
      }

      template<typename T>
      const XMLAttributeHandle & XMLAttributeHandle::operator>>(T & val) const
      {
        std::stringstream str;
        str << Element->Attributes[Index].Value;
        str >> val;
        return *this;
      }

      template<typename T>
      const ConstXMLAttributeHandle & ConstXMLAttributeHandle::operator>>(T & val) const
      {
        std::stringstream str;
        str << Element->Attributes[Index].Value;
        str >> val;
        return *this;
      }
    }
  }
}