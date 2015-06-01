#include <string>
#include "R_StrUtils.h"

namespace alchemy
{
	char toUpper(char input)
	{
		//If we have input that is a lowercase letter...
		if (input >= 'a' && input <= 'z')
			return input - ('a' - 'A');
		return input;
	}

	std::string& toUpper(std::string &str)
	{
		//Make the spell uppercase.
		for (unsigned int i = 0; i < str.size(); ++i)
			str.at(i) = alchemy::toUpper(str.at(i));

		return str;
	}

	char toLower(char input)
	{
		//If we have input that is a lowercase letter...
		if (input >= 'A' && input <= 'Z')
			return input - ('A' - 'a');
		return input;
	}

	std::string& toLower(std::string &str)
	{
		//make the spell lowercase.
		for (unsigned int i = 0; i < str.size(); ++i)
			str.at(i) = toLower(str.at(i));

		return str;
	}

	bool operator>(std::string& str1, std::string& str2)
	{
		return str1.compare(str2) > 0;
	}

	bool operator<(std::string& str1, std::string& str2)
	{
		return str1.compare(str2) < 0;
	}

	bool operator==(std::string& str1, std::string& str2)
	{
		if (!(str1 < str2))
			if (!(str1 > str2))
				return true;
		return false;
	}

	bool operator!=(std::string& str1, std::string& str2)
	{
		return !(str1 == str2);
	}
}
