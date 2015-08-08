#include "XMLFile.h"


namespace MistThread
{
  namespace IO
  {
    namespace XML
    {
      char GetNextChar(std::fstream & file)
      {
        char c;
        if(!file.get(c))
          throw std::exception("Invalid XML, End of file not expected");
        return c;
      }

      XMLFile::XMLFile(std::string path)
      {
        std::fstream file(path);
        if(!file.is_open())
          throw std::exception("Couldn't open file");


        int lineNumber = 1;

        while(!file.eof())
        {
          char c;
          //get the character if it doesn't work break
          if(!file.get(c))
            break;

          //do we have the start of a tag
          if(c == '<')
          {
            char currentChar = GetNextChar(file);


            //is this the end of an element
            if(currentChar == '/')
            {
              std::string ElementName;
              currentChar = GetNextChar(file);
              do
              {
                ElementName += currentChar;

                currentChar = GetNextChar(file);

                //if we reach the end of the line throw an exeption
                if(currentChar == '\n' || currentChar == '\r')
                  throw std::exception("Invalid XML, End of line not expected"); //todo give a line number

              } while(currentChar != ' ' && currentChar != '>');
              if(ElementName == ActiveElements.top()->Name)
                ActiveElements.pop();
              else
                throw std::exception("Invalid XML, Active tag must be closed first!"); //todo say which tag and where
            }
            else
            {
              std::string ElementName;

              //get the name of the element
              do
              {
                ElementName += currentChar;

                currentChar = GetNextChar(file);

                //if we reach the end of the line throw an exeption
                if(currentChar == '\n' || currentChar == '\r')
                  throw std::exception("Invalid XML, End of line not expected"); //todo give a line number

              } while(currentChar != ' ' && currentChar != '>' && currentChar != '/');

              //push this new element
              if(ActiveElements.size() == 0)
              {
                Elements.push_back(XMLElement(ElementName));
                ActiveElements.push(&Elements.back());
              }
              else
              {
                ActiveElements.top()->Elements.push_back(XMLElement(ElementName));
                ActiveElements.push(&ActiveElements.top()->Elements.back());
              }

              //if the tag is self closing, close it
              if(currentChar == '/')
                ActiveElements.pop();
              else if(currentChar == ' ')
              {
                //get some attributes
                do
                {
                  //clear some whitespace
                  while(currentChar == ' ')
                  {
                    currentChar = GetNextChar(file);
                  }

                  std::string attributeName;
                  do
                  {
                    attributeName += currentChar;

                    currentChar = GetNextChar(file);

                  } while(currentChar != '=' && currentChar != ' ');

                  //clear whitespace
                  do
                  {
                    currentChar = GetNextChar(file);
                  } while(currentChar == ' ' || currentChar == '=');

                  if(currentChar != '"')
                    throw std::exception("invalid XML, Expected Attribute value"); //todo add a line number

                  currentChar = GetNextChar(file);

                  std::string value;
                  while(currentChar != '"')
                  {
                    value += currentChar;

                    currentChar = GetNextChar(file);

                  }

                  ActiveElements.top()->Attributes.push_back(XMLAttribute(attributeName, value));

                  //clear whitespace
                  do
                  {
                    currentChar = GetNextChar(file);
                  } while(currentChar == ' ' || currentChar == '=');
                  //if we reach the end of the line throw an exeption
                  if(currentChar == '\n' || currentChar == '\r')
                    throw std::exception("Invalid XML, End of line not expected"); //todo give a line number

                } while(currentChar != '>' && currentChar != '/');

                //if the tag is self closing, close it
                if(currentChar == '/')
                  ActiveElements.pop();
              }
            }
          }
          if(c == '\n')
            ++lineNumber;
        }

        if(ActiveElements.size() != 0)
          throw std::exception("Not all tags closed"); //todo add which one isn't

      }

      XMLFile::~XMLFile()
      {

      }
    }
  }
}
