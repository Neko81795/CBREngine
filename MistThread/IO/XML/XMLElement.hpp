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

      template <typename T>
      XMLAttributeHandle XMLElement::AddAttribute(const std::string &name, const T&value)
      {
        std::stringstream str;
        str << value;
        Attributes.push_back(XMLAttribute(name, str.str()));
        return XMLAttributeHandle(static_cast<int>(Attributes.size()) - 1, this);
      }

      template <typename T>
      void XMLElement::SetAttribute(const std::string &name, const T& value)
      {
        std::vector<XMLAttributeHandle> attribs = GetAttributesByName(name);
        if (attribs.size() == 0)
        {
          AddAttribute(name, value);
        }
        else
        {
          std::stringstream str;
          str << value;
          attribs[0]->Value = str.str();
        }
      }

      template <>
      inline void XMLElement::SetAttribute<std::string>(const std::string &name, const std::string& value)
      {
        std::vector<XMLAttributeHandle> attribs = GetAttributesByName(name);
        if (attribs.size() == 0)
          AddAttribute(name, value);
        else
          attribs[0]->Value = value;
      }


      /*********************************************
      * XMLAttributeHandle
      *********************************************/


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