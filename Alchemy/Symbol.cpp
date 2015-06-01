#include "Symbol.h"
#include <string>
#include <vector>
#include <fstream>

namespace alchemy
{
  static void ImportFromFile(std::string stats)
  {
    std::ifstream iFile(stats); //The name of the stats file

    for (int i = 0; i < SYMBOL_COUNT; ++i)
    {
      Symbol::symbolStats.at(0).damageScalar = 1;
    }
  }
}


