#include <string>
#include <algorithm>
#include <vector>
#include <sstream>

#include "Spell.h"
#include "SpellSymbols.h"
#include "R_StrUtils.h"

namespace alchemy
{
	Spell::Spell()
	{
		//Create a new empty string.
		spell_ = "";
		spellData_.Clear();
	}

	Spell::Spell(string str)
	{
		//Use existing systems to perform a deep copy.
		spell_ = str.substr(0, str.size());
		spellData_.ParseNew(str);
	}

	Spell::~Spell()
	{
		//Put destructor stuff here.
	}

	bool localComparator(string i, string j) { return (i<j); }
	double Spell::checkValidity(std::vector<std::string> &dictionary, int dictionarySize)
	{
		double numberValid = 0;          //Number of valid words.
		string tempStr = string(spell_); //A temp version of our string to butcher.
		vector<string> splitWords;       //A vector to hold what we split.
		string tempBuffer;				 //A temp buffer to hold the output mid-process.
		stringstream ss(tempStr);        //A stringstream to auto feed to the buffer split on spaces.

		//While there are still spaces, split on the spaces.
		while (ss >> tempBuffer)
			splitWords.push_back(tempBuffer);

		//For every word we parsed, check if it is valid.
		for (unsigned int i = 0; i < splitWords.size(); ++i)
			numberValid += std::binary_search(dictionary.begin(), dictionary.end(), splitWords.at(i), localComparator);

		//If we have words parsed that we can actually use to divide...
		if (splitWords.size())
			return numberValid / splitWords.size();
		return 0;
	}

	Spell& Spell::toUpper()
	{
		//make the spell uppercase.
		alchemy::toUpper(spell_);

		return *this;
	}

	Spell& Spell::toLower()
	{
		//make the spell lowrcase.
		alchemy::toLower(spell_);

		return *this;
	}

	string& Spell::getString()
	{
		//Return the underlying string.
		return spell_;
	}

	Spell& Spell::operator=(Spell& rhs)
	{
		//Perform a deep copy usnig existing functions.
		spell_ = rhs.getString().substr(0, rhs.getString().size());
		spellData_ = rhs.spellData_;

		//Return a reference to the current string.
		return *this;
	}

	Spell& Spell::operator=(string rhs)
	{
		//Assign our spell based on the other.
		spell_ = rhs.substr(0, rhs.size());
		spellData_.ParseNew(rhs);

		//return a reference to our spell.
		return *this;
	}

	ostream& operator<<(ostream& os, const Spell rhs)
	{
		//Print our spell and all data associated with it.
		os << rhs.spell_ << "\n";
		os << rhs.spellData_;

		//Return our stream reference.
		return os;
	}

}