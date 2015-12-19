#pragma once
#include <vector>
#include <string>
#include <ostream>
#include "XMLAttribute.h"

namespace MistThread
{
  namespace IO
  {
    namespace XML
    {
      class XMLAttributeHandle;
      class ConstXMLAttributeHandle;

      class XMLElement
      {
      public:
        std::vector<XMLElement> Elements;
        std::vector<XMLAttribute> Attributes;

        std::string Name;

        /// <summary>
        /// returns the first element with the given name
        /// </summary>
        /// <param name="name">the name of the element to find</param>
        /// <exception cref="Core::Exception">thrown when the element can't be found</exception>
        XMLElement *GetElementByName(const std::string &name);
        /// <summary>
        /// returns the first element with the given name
        /// </summary>
        /// <param name="name">the name of the element to find</param>
        /// <exception cref="Core::Exception">thrown when the element can't be found</exception>
        const XMLElement *GetElementByName(const std::string &name) const;
        /// <summary>
        /// returns the first attribute with the given name
        /// </summary>
        /// <param name="name">the name of the attribute to find</param>
        /// <exception cref="Core::Exception">thrown when the attribute can't be found</exception>
        XMLAttributeHandle GetAttributeByName(const std::string &name);
        /// <summary>
        /// returns the first attribute with the given name
        /// </summary>
        /// <param name="name">the name of the attribute to find</param>
        /// <exception cref="Core::Exception">thrown when the attribute can't be found</exception>
        ConstXMLAttributeHandle GetAttributeByName(const std::string &name) const;

        /// <summary>
        /// returns the value of the first attribute with the given name or the default value of T
        /// </summary>
        /// <param name="name">the name of the attribute to find</param>
        template <typename T = std::string>
        T GetAttributeValueByName(const std::string &name) const;
        /// <summary>
        /// returns the value of the first attribute with the given name or the default if not found
        /// </summary>
        /// <param name="name">the name of the attribute to find</param>
        /// <param name="def">the default value</param>
        template <typename T>
        T GetAttributeValueByName(const std::string &name, const T& def) const;
        /// <summary>
        /// returns all elements with the given name
        /// </summary>
        /// <param name="name">the name of the elements to find</param>
        std::vector<XMLElement*> GetElementsByName(const std::string &name);
        /// <summary>
        /// returns all elements with the given name
        /// </summary>
        /// <param name="name">the name of the elements to find</param>
        std::vector<const XMLElement*> GetElementsByName(const std::string &name) const;
        /// <summary>
        /// returns all attributes with the given name
        /// </summary>
        /// <param name="name">the name of the attributes to find</param>
        std::vector<XMLAttributeHandle> GetAttributesByName(const std::string &name);
        /// <summary>
        /// returns all attributes with the given name
        /// </summary>
        /// <param name="name">the name of the attributes to find</param>
        std::vector<ConstXMLAttributeHandle> GetAttributesByName(const std::string &name) const;
        /// <summary>
        /// Adds a new element with the given name and returns a reference
        /// </summary>
        /// <param name="name">the name to give the new element</param>
        XMLElement* AddElement(const std::string &name);
        /// <summary>
        /// Adds a new attribute with the given name and value and returns a reference
        /// </summary>
        /// <param name="name">the name of the new attribute</param>
        /// <param name="value">the value of the new attribute</param>
        XMLAttributeHandle AddAttribute(const std::string &name, const std::string& value = "");
        /// <summary>
        /// Adds a new attribute with the given name and value and returns a reference
        /// </summary>
        /// <param name="name">the name of the new attribute</param>
        /// <param name="value">the value of the new attribute</param>
        template <typename T>
        XMLAttributeHandle AddAttribute(const std::string &name, const T& value = T());
        /// <summary>
        /// Sets the value of the first attribute with the given name, creates one if it can't find it
        /// </summary>
        /// <param name="name">the name of the attribute to set</param>
        /// <param name="value">the new value</param>
        template <typename T>
        void SetAttribute(const std::string& name, const T& value = T());

        friend std::ostream &operator<<(std::ostream &stream, const XMLElement& element);

        XMLElement(const std::string &name);
        ~XMLElement();
      };

      class XMLAttributeHandle
      {
        friend class XMLElement;
      public:
        XMLAttributeHandle(int index, XMLElement* element);

        template<typename T>
        const XMLAttributeHandle& operator >>(T& val) const;
        XMLAttribute& operator*();
        XMLAttribute operator*() const;
        XMLAttribute* operator->();
        XMLAttribute const * operator->() const;
      private:
        XMLElement* Element;
        int Index;
      };

      class ConstXMLAttributeHandle
      {
        friend class XMLElement;
      public:
        ConstXMLAttributeHandle(int index, XMLElement const* element);

        template<typename T>
        const ConstXMLAttributeHandle& operator >>(T& val) const;
        XMLAttribute operator*() const;
        XMLAttribute const * operator->() const;
      private:
        XMLElement const* Element;
        int Index;
      };
    }
  }
}

#include "XMLElement.hpp"
