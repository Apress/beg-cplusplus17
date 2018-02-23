// Exercising the use of standard functors
#include <iostream>
#include <functional>
#include "Optimum.h"

int main()
{
  std::vector<int> numbers{ 91, 18, 92, 22, 13, 43 };
  std::cout << "Minimum element: " << *find_optimum(numbers, std::less<>{}) << std::endl;
  std::cout << "Maximum element: " << *find_optimum(numbers, std::greater<>{}) << std::endl;
}
