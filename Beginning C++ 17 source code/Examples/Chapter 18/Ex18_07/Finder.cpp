// Exercising capturing the this pointer
#include "Finder.h"
#include "Optimum.h"
#include <cmath>       // For std::abs()

int Finder::getNumberToSearchFor() const
{
  return number_to_search_for;
}

void Finder::setNumberToSearchFor(int value)
{
  number_to_search_for = value;
}

std::optional<int> Finder::findNearest(const std::vector<int>& values) const
{
  if (values.empty())
    return std::nullopt;
  else  
    return *find_optimum(values, [this](int x, int y) {
      return std::abs(x - number_to_search_for) < std::abs(y - number_to_search_for);
    });
}
