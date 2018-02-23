// Exercising the use of a functor as callback functions
#include <iostream>
#include "Optimum.h"
#include "Less.h"

template <typename T>
bool greater(const T& one, const T& other) { return one > other; }

int main()
{
  Less less;     // Create a 'less than' functor

  std::vector<int> numbers{ 91, 18, 92, 22, 13, 43 };
  std::cout << "Minimum element: " << *find_optimum(numbers, less) << std::endl;
  std::cout << "Maximum element: " << *find_optimum(numbers, greater<int>) << std::endl;
}
