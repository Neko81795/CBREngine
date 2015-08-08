#include "Symbol.h"
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

namespace alchemy
{
  std::vector<Symbol> Symbol::symbolStats(SYMBOL_COUNT);

  /// <summary>
  /// Updates the static information for all of the symbols present.
  /// </summary>
  /// <param name="stats">The name of the file to import from.</param>
  void Symbol::ImportFromFile(std::string stats)
  {
    std::ifstream iFile(stats); //The name of the stats file

    //Added one to the loop condition to account for labels at the top of the file.
    for (int i = 0; i < SYMBOL_COUNT + 1; ++i)
    {
      std::vector<double> splitVals; //A vector to hold what we split.
      std::string currentString;     //The current string being worked with.
      std::string tempBuffer;				 //A temp buffer to hold the output mid-process.

      std::getline(iFile, currentString);
      
      std::stringstream ss(currentString);

      if (i != 0)
      {
        for (int j = 0; ss >> tempBuffer; ++j)
        {
          if (j)
          {
            double convertedScalarValue = std::stod(tempBuffer);

            if (convertedScalarValue <= 0.01)
              convertedScalarValue = 1;
            splitVals.push_back(convertedScalarValue);
          }
        }

        /* Add each letter's value. Could probably be condensed into an array, 
        but this will generally be more readable later. If it is not, please
        do feel free how the values are stored.*/
        alchemy::Symbol::symbolStats.at(i - 1).damageScalar = splitVals[0];
        alchemy::Symbol::symbolStats.at(i - 1).durationScalar = splitVals[1];
        alchemy::Symbol::symbolStats.at(i - 1).instanceCountScalar = splitVals[2];
        alchemy::Symbol::symbolStats.at(i - 1).aoeScalar = splitVals[3];
        alchemy::Symbol::symbolStats.at(i - 1).knockbackScalar = splitVals[4];
        alchemy::Symbol::symbolStats.at(i - 1).recoilScalar = splitVals[5];
      }
    }
  }

}


