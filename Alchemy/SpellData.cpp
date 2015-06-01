#include <string>

#include "SpellSymbols.h"
#include "SpellData.h"

using namespace std;

namespace alchemy
{
	//Default constructor.
	SpellData::SpellData()
	{
		//All we need to do is make sure all our data is cleared to remove garbage.
		Clear();
	}


	void SpellData::Clear()
	{
		//Set all data to 0 to remove old data or garbage.
		for (int i = 0; i < SYMBOL_COUNT; ++i)
			data_[i] = 0;
	}


	//Returns the data array.
	int* SpellData::GetData()
	{
		return data_;
	}


	//Parses in a new string to the data set, updating it all.
	int& SpellData::ParseNew(string& str)
	{
		//Clear out the old data
		Clear();

		//Populate with new data regardless of uppercase or lowercase.
    for (unsigned int i = 0; i < str.size(); ++i)
      if (isupper(str.at(i)))
      {
        auto index = str.at(i) - UPPERCASE_ASCII_INDEX;
        ++(data_[index]);
        FactorIn(static_cast<alchemy::SpellSymbols>(index));
      }
      else if (islower(str.at(i)))
      {
        auto index = str.at(i) - LOWERCASE_ASCII_INDEX;
        ++(data_[index]);
        FactorIn(static_cast<alchemy::SpellSymbols>(index));
      }

		//Return a reference in case someone wants to use it.
		return *data_;
	}


	void SpellData::FactorIn(Symbol &toAdd)
	{
		FactorInAtPercentage(toAdd, 1);
	}
  
  void SpellData::FactorIn(SpellSymbols symbol)
  {
    FactorIn(alchemy::Symbol::symbolStats[symbol]);
  }

	void Scale(double &toScale, double scalar, double intensityScalar) { toScale *= (scalar * intensityScalar); }
	void SpellData::FactorInAtPercentage(Symbol &toAdd, float intensityScalar)
	{
		//Scale the appropriate values by the letter value.
		Scale(damage_, toAdd.damageScalar, intensityScalar);
		Scale(duration_, toAdd.durationScalar, intensityScalar);
		Scale(instanceCount_, toAdd.instanceCountScalar, intensityScalar);
		Scale(aoe_, toAdd.aoeScalar, intensityScalar);
		Scale(knockback_, toAdd.knockbackScalar, intensityScalar);
		Scale(recoil_, toAdd.recoilScalar, intensityScalar);

		//Set the color to default to a ³128­ grey value.
		color_.SetA(.5f * (toAdd.colorScalar.A() / .5f));
		color_.SetR(.5f * (toAdd.colorScalar.R() / .5f));
		color_.SetG(.5f * (toAdd.colorScalar.G() / .5f));
		color_.SetB(.5f * (toAdd.colorScalar.B() / .5f));
	}


	std::ostream& operator<<(std::ostream& os, const SpellData& rhs)
	{
		//Insert the array into the stream so we can visualize it.
		for (int i = 0; i < SYMBOL_COUNT; ++i)
			os << (char)('A' + i) << ": " << rhs.data_[i] << "\n";

		os << "Damage: " << rhs.damage_ << "\n";
		os << "Duration: " << rhs.duration_ << "\n";
		os << "Instance Count: " << rhs.instanceCount_ << "\n";
		os << "AOE: " << rhs.aoe_ << "\n";
		os << "Knockback: " << rhs.aoe_ << "\n";
		os << "Recoil: " << rhs.recoil_ << "\n";
		os << "Color- A:" << rhs.color_.A() << " R:" << rhs.color_.R() << " G:" << rhs.color_.G() << " B:" << rhs.color_.B() << std::endl;
		return os;
	}
}