#pragma once

#include "SpellSymbols.h"
#include <string.h>
#include "Symbol.h"

using namespace std;

namespace alchemy
{
	class SpellData
	{
	public:
		
		//Constructors
		SpellData();
		
		void Clear();
		int* GetData();
		int& ParseNew(string& str);

		void FactorIn(Symbol &toAdd);
    void FactorIn(SpellSymbols s);
		void FactorInAtPercentage(Symbol &toAdd, float intensityScalar);

		//Operator Overloads
		friend std::ostream& operator<<(std::ostream& os, const SpellData& rhs);

	private:
		int data_[SYMBOL_COUNT]; //An array holding data for our symbols.

		double damage_ = 1;        //The damage of the spell.
		double duration_ = 1;      //The duration of the spell.
		double instanceCount_ = 1; //The number of different instances of the spell parts are produced. (An attack that shoots 3 balls out instead of 1. This would increase the number of balls.)
		double aoe_ = 1;           //The size of the Area of Effect.
		double knockback_ = 1;	   //The knockback caused by the spell.
		double recoil_ = 1;		     //The recoil caused by the spell.

		//The color of the spell.
		CBREngine::Graphics::Color color_ = CBREngine::Graphics::Color(.5f, .5f, .5f);
	};
}
