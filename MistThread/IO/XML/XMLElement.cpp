#include "XMLElement.h"
#include "Core/Exception.h"

namespace MistThread
{
  namespace IO
  {
    namespace XML
    {
      XMLElement * XMLElement::GetElementByName(const std::string &name)
      {
        for (unsigned int i = 0; i < Elements.size(); i++)
        {
          if (Elements[i].Name == name)
            return &Elements[i];
        }
        return nullptr;
      }

      const XMLElement * XMLElement::GetElementByName(const std::string &name) const
      {
        for (unsigned int i = 0; i < Elements.size(); i++)
        {
          if (Elements[i].Name == name)
            return &Elements[i];
        }
        return nullptr;
      }

      XMLAttributeHandle XMLElement::GetAttributeByName(const std::string &name)
      {
        for (unsigned int i = 0; i < Attributes.size(); i++)
        {
          if (Attributes[i].Name == name)
            return XMLAttributeHandle(i, this);
        }
        return XMLAttributeHandle(-1, this);
      }

      ConstXMLAttributeHandle XMLElement::GetAttributeByName(const std::string & name) const
      {
        for (unsigned int i = 0; i < Attributes.size(); i++)
        {
          if (Attributes[i].Name == name)
            return ConstXMLAttributeHandle(i, this);
        }
        return ConstXMLAttributeHandle(-1, this);
      }

      std::vector<XMLElement *> XMLElement::GetElementsByName(const std::string &name)
      {
        std::vector<XMLElement*> elements;

        for (unsigned int i = 0; i < Elements.size(); i++)
        {
          if (Elements[i].Name == name)
            elements.push_back(&Elements[i]);
        }

        return elements;
      }

      std::vector<const XMLElement*> XMLElement::GetElementsByName(const std::string & name) const
      {
        std::vector<const XMLElement*> elements;

        for (unsigned int i = 0; i < Elements.size(); i++)
        {
          if (Elements[i].Name == name)
            elements.push_back(&Elements[i]);
        }

        return elements;
      }

      std::vector<XMLAttributeHandle> XMLElement::GetAttributesByName(const std::string &name)
      {
        std::vector<XMLAttributeHandle> attributes;
        for (unsigned int i = 0; i < Attributes.size(); i++)
        {
          if (Attributes[i].Name == name)
            attributes.emplace_back(i, this);
        }
        return attributes;
      }

      std::vector<ConstXMLAttributeHandle> XMLElement::GetAttributesByName(const std::string & name) const
      {
        std::vector<ConstXMLAttributeHandle> attributes;
        for (unsigned int i = 0; i < Attributes.size(); i++)
        {
          if (Attributes[i].Name == name)
            attributes.emplace_back(i, this);
        }
        return attributes;
      }

      XMLElement* XMLElement::AddElement(const std::string &name)
      {
        Elements.push_back(XMLElement(name));
        return &Elements.back();
      }

      XMLAttributeHandle XMLElement::AddAttribute(const std::string &name, const std::string &value)
      {
        Attributes.push_back(XMLAttribute(name, value));
        return XMLAttributeHandle(static_cast<int>(Attributes.size()) - 1, this);
      }

      std::string InsertSpaces(int tabDepth)
      {
        std::string str;
        for (int i = 0; i < tabDepth; i++)
        {
          str += "  ";
        }
        return str;
      }

      std::ostream &operator<<(std::ostream &stream, const XMLElement& element)
      {
        static int tabDepth = 0;
        stream << InsertSpaces(tabDepth) << "<" << element.Name;
        ++tabDepth;

        for (unsigned int i = 0; i < element.Attributes.size(); i++)
        {
          stream << " " << element.Attributes[i].Name << "=\"" << element.Attributes[i].Value << "\"";
        }

        if (element.Elements.size() == 0)
        {
          stream << "/>" << std::endl;
          --tabDepth;
        }
        else
        {
          stream << ">" << std::endl;

          for (unsigned int i = 0; i < element.Elements.size(); i++)
          {
            stream << element.Elements[i];
          }
          --tabDepth;
          stream << InsertSpaces(tabDepth) << "</" << element.Name << ">" << std::endl;
        }

        return stream;
      }

      void XMLElement::SetAttribute(const std::string &name, const std::string &value)
      {
        std::vector<XMLAttributeHandle> attribs = GetAttributesByName(name);
        if (attribs.size() == 0)
          AddAttribute(name, value);
        else
          attribs[0]->Value = value;
      }

      XMLElement::XMLElement(const std::string &name)
      {
        Name = name;
      }

      XMLElement::~XMLElement()
      {

      }

      XMLAttributeHandle::XMLAttributeHandle(int index, XMLElement* element) : Index(index), Element(element) { }

      XMLAttribute & XMLAttributeHandle::operator*()
      {
        return Element->Attributes[Index];
      }

      XMLAttribute XMLAttributeHandle::operator*() const
      {
        return Element->Attributes[Index];
      }

      XMLAttribute * XMLAttributeHandle::operator->()
      {
        return &Element->Attributes[Index];
      }

      XMLAttribute const * XMLAttributeHandle::operator->() const
      {
        return &Element->Attributes[Index];;
      }

      ConstXMLAttributeHandle::ConstXMLAttributeHandle(int index, XMLElement const* element) : Index(index), Element(element) {}

      XMLAttribute ConstXMLAttributeHandle::operator*() const
      {
        return Element->Attributes[Index];
      }

      XMLAttribute const * ConstXMLAttributeHandle::operator->() const
      {
        return &Element->Attributes[Index];;
      }
    }
  }
}
