#include "Random.h"

std::default_random_engine Random::generator_(static_cast<unsigned int>(std::chrono::system_clock::now().time_since_epoch().count()));

double Random::RandRange(double low, double high)
{
  std::uniform_real_distribution<double> distribution(low, high);
  return distribution(generator_);
}

double Random::Rand()
{
  std::uniform_real_distribution<double> distribution(0.0, 1.0);
  return distribution(generator_);
}