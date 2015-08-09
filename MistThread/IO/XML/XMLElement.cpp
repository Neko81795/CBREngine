#include "XMLElement.h"

namespace MistThread
{
  namespace IO
  {
    namespace XML
    {
      XMLElement & XMLElement::GetElementByName(const std::string &name)
      {
        for(unsigned int i = 0; i < Elements.size(); i++)
        {
          if(Elements[i].Name == name)
            return Elements[i];
        }
        throw std::exception("Could not find Element");
      }

      XMLAttribute & XMLElement::GetAttributeByName(const std::string &name)
      {
        for(unsigned int i = 0; i < Attributes.size(); i++)
        {
          if(Attributes[i].Name == name)
            return Attributes[i];
        }
        throw std::exception("Could not find Attribute");
      }

      const XMLAttribute & XMLElement::GetAttributeByName(const std::string & name) const
      {
        for(unsigned int i = 0; i < Attributes.size(); i++)
        {
          if(Attributes[i].Name == name)
            return Attributes[i];
        }
        throw std::exception("Could not find Attribute");
      }

      std::vector<XMLElement *> XMLElement::GetElementsByName(const std::string &name)
      {
        std::vector<XMLElement*> elements;

        for(unsigned int i = 0; i < Elements.size(); i++)
        {
          if(Elements[i].Name == name)
            elements.push_back(&Elements[i]);
        }

        return elements;
      }

      std::vector<const XMLElement*> XMLElement::GetElementsByName(const std::string & name) const
      {
        std::vector<const XMLElement*> elements;

        for(unsigned int i = 0; i < Elements.size(); i++)
        {
          if(Elements[i].Name == name)
            elements.push_back(&Elements[i]);
        }

        return elements;
      }

      std::vector<XMLAttribute*> XMLElement::GetAttributesByName(const std::string &name)
      {
        std::vector<XMLAttribute*> attributes;
        for(unsigned int i = 0; i < Attributes.size(); i++)
        {
          if(Attributes[i].Name == name)
            attributes.push_back(&Attributes[i]);
        }
        return attributes;
      }

      std::vector<const XMLAttribute*> XMLElement::GetAttributesByName(const std::string & name) const
      {
        std::vector<const XMLAttribute*> attributes;
        for(unsigned int i = 0; i < Attributes.size(); i++)
        {
          if(Attributes[i].Name == name)
            attributes.push_back(&Attributes[i]);
        }
        return attributes;
      }

      XMLElement & XMLElement::AddElement(const std::string &name)
      {
        Elements.push_back(XMLElement(name));
        return Elements.back();
      }

      XMLAttribute & XMLElement::AddAttribute(const std::string &name, const std::string &value)
      {
        Attributes.push_back(XMLAttribute(name, value));
        return Attributes.back();
      }

      std::string InsertSpaces(int tabDepth)
      {
        std::string str;
        for(int i = 0; i < tabDepth; i++)
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

        for(unsigned int i = 0; i < element.Attributes.size(); i++)
        {
          stream << " " << element.Attributes[i].Name << "=\"" << element.Attributes[i].Value << "\"";
        }

        if(element.Elements.size() == 0)
        {
          stream << "/>" << std::endl;
          --tabDepth;
        }
        else
        {
          stream << ">" << std::endl;

          for(unsigned int i = 0; i < element.Elements.size(); i++)
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
        std::vector<XMLAttribute*> attribs = GetAttributesByName(name);
        if(attribs.size() == 0)
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
    }
  }
}
