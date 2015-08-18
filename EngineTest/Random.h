#pragma once
#include <chrono>
#include <random>

class Random
{
public:
  static double Rand();
  static double RandRange(double low, double high);

private:
  static std::default_random_engine generator_;
};