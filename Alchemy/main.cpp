#include <stdio.h>
#include <assert.h>
//File IO
#include <iostream>
#include <fstream>
//Containers
#include <string>
#include <vector>

#include "Symbol.h"
#include "Spell.h"
#include "R_StrUtils.h"

//Prototypes
void quickSpellTest();
void quickStringCompareTest();
void setToBeginning(ifstream &ifs);

void main()
{
	alchemy::Spell spell;					//Storage for the spell we will cast, and subsequently the word that was read in.
	std::string input;						//The input string for the spell we will cast.
	vector<string> words;					//A pointer to an array of words.
	ifstream iFile("sorted_lexicon.txt");	//Input File Stream for the words we have.
	int lines = 0;							  //The number of lines in the wordsFile, as of now.
	
	//Test things.
	//quickSpellTest();
	//quickStringCompareTest();
	//return;

	//Load file.
	if (iFile.is_open())
	{
		//Count our lines.
		while (iFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n'))
			++lines;

		//Move to the beginning after we have counted.
		setToBeginning(iFile);

		//Update the user.
		cout << "File Found, with " << lines << " entries!\n";
		cout << "Allocating and populating memory...\n";

		//Allocate the memory.
		words = vector<string>(lines + 1);

		//Populate the lines in memory.
		int currLine = 0;
		while (getline(iFile, words.at(currLine)))
			++currLine;
    
		//Update the user.
		cout << "Making words a uniform case...\n";

		//Make all words lowercase.
		for (int i = 0; i < lines; ++i)
			alchemy::toUpper(words.at(i));

		//Update the user.
		//cout << "Sorting the dictionary...\n";
		//Sorting dictionary.
		//std::sort(words.begin(), words.end(), localComparator);
    
		//Update the user.
		cout << "Lexicon ready for searching.\n";

    cout << "Reading in scalar configuration for symbols...\n";
    alchemy::Symbol::ImportFromFile("scalar_config.txt");
	}
	else
	{
		//Inform the user you failed to find the file, and exit the program.
		cout << "Failed to find file!" << "\n";
		system("pause");
		return;
	}

	while (1)
	{
		//Prompt and read in a word.
		cout << "Please enter a word or phrase: ";
		getline(cin, input);
		spell = alchemy::Spell(input);

		//Print out spell.
		cout << spell;
		spell.toUpper();
		if (words.size() > 0)
			cout << "word state: " << spell.checkValidity(words, lines) << "\n";
		cout << "\n";
	}
}



void setToBeginning(ifstream &ifs)
{
	//Reset to beginning of file.
	ifs.clear();
	ifs.seekg(0, ios::beg);
}



void quickSpellTest()
{
	//Make empty spell.
	alchemy::Spell test;
	cout << test;

	//Will make a noise.
	for (int i = 0; i < 128; ++i)
	{
		char c[2];
		#pragma warning( disable : 4996 )
		sprintf(c, "%c", i);
		cout << (test = c);
	}

	//Crappy convoluted word test.
	test = "Spell Here Please 44551asdf!@@@452q34!!%$^&$**#()@_";
	cout << test;
	cout << test.toUpper();
	cout << test.toLower();
	cout << test.getString() << endl;
}



void quickStringCompareTest()
{
	using namespace alchemy;

	cout << "Testing operator overloads...\n";
	assert((std::string("Hella") < std::string("Iella") == true));
	assert((std::string("Hella") < std::string("apple") == true));
	assert((std::string("zzzz") < std::string("aaaa") == false));
	assert((std::string("yolo") > std::string("Aaa") == true));
	assert((std::string("yolo") > std::string("aaa") == true));
	assert((std::string("yolo") > std::string("zaaa") == false));
	cout << "...passed.\n";
}