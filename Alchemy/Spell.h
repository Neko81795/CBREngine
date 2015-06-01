#ifndef SpellClass_H
#define SpellClass_H

#include <string>
#include <string.h>

#include "SpellData.h"

using namespace std;

namespace alchemy
{
	class Spell
	{

	public:
		//////////////////////////////
		//Constructors and Destructors
		//////////////////////////////
		Spell();
		Spell(string str);
		~Spell();


		//////////////////////////////
		//Member Functions
		//////////////////////////////

		//Returns a value between 0 and 1 that indicates how valid the word string is.
		double checkValidity(std::vector<std::string> &dictionary, int dictionarySize);

		//Converts all of the characters in the string to uppercase or lowercase.
		Spell& toUpper();
		Spell& toLower();


		//////////////////////////////
		//Getters and Setters
		//////////////////////////////
      
		//returns the string entered.
		string& getString();
        

		//////////////////////////////
		//Operator Overloads
		//////////////////////////////

		//Assingment operator
		Spell& operator=(Spell& rhs);
		Spell& operator=(string rhs);

		//Allow for printing
		friend ostream& operator<<(ostream& os, const Spell rhs);

	private:
		string spell_;
		SpellData spellData_;

		//////////////////////////////
		//Private Member Functions
		//////////////////////////////

	};
}
#endif //SpellClass_H
