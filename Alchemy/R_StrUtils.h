#ifndef R_StrUtils_H
#define R_StrUtils_H

#include <string>

namespace alchemy
{
	//Convert character or string to uppercase.
	char toUpper(char input);
	std::string& toUpper(std::string &str);

	//Convert character or string to lowercase.
	char toLower(char input);
	std::string& toLower(std::string &str);

	//String operator overloading.
	bool operator>(std::string& str1, std::string& str2);
	bool operator<(std::string& str1, std::string& str2);
	bool operator==(std::string& str1, std::string& str2);
	bool operator!=(std::string& str1, std::string& str2);
}

#endif //R_StrUtils_H
