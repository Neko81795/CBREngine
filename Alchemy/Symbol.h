#ifndef Symbol_H
#define Symbol_H

#include "tempCBR\Color.h"
#include <vector>
#include <string>

namespace alchemy
{
	class Symbol
	{
	public:
		double damageScalar = 1;        //A scalar for the damage of the spell.
		double durationScalar = 1;      //A scalar for the duration of the spell.
		double instanceCountScalar = 1; //A scalar for the number of different instances of the spell parts are produced. (An attack that shoots 3 balls out instead of 1. This would increase the number of balls.)
		double aoeScalar = 1;           //A scalar to determine the size of the Area of Effect.
		double knockbackScalar = 1;		//A Scalar to adjust the knockback caused by the spell.
		double recoilScalar = 1;		//A Scalar to determine recoil of the caster.

		void(*effect)() = 0;            //A pointer to an effect function. Called on a per-cycle basis.
		
		//A color to use as a scalar for default.
		CBREngine::Graphics::Color colorScalar = CBREngine::Graphics::Color(.5f, .5f, .5f); 

		static std::vector<Symbol> symbolStats;
    static void ImportFromFile(std::string s);
	};

	enum SpellSymbols
	{
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		SYMBOL_COUNT
	};
}

#endif //Symbol
