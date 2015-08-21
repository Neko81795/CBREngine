#pragma once
#include <chrono>
#include <random>



class Random
{
  public:
    /// <summary>
    /// Provides a random double from 0.0 to 1.0.
    /// </summary>
    static double Rand();
    /// <summary>
    /// Provides a random double within the specified range.
    /// </summary>
    /// <param name="low">The lowest value the double can be.</param>
    /// <param name="high">The highest value the double can be.</param>
    static double RandRange(double low, double high);

  private:
    static std::default_random_engine generator_; //The generator to be used for all random generation. Seeded with the time.
};