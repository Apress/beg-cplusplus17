#include "compare.h"
#include <limits>             // For std::numeric_limits<>::infinity()

// Function to find the maximum
double compare::max(const std::vector<double>& data)
{
  double result { -std::numeric_limits<double>::infinity() };
  for (const auto value : data)
    if (value > result) result = value;
  return result;
}

// Function to find the minimum
double compare::min(const std::vector<double>& data)
{
  double result { std::numeric_limits<double>::infinity() };
  for (const auto value : data)
    if (value < result) result = value;
  return result;
}
