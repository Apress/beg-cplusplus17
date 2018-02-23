// Exercising a function object with a member variable
#include <iostream>
#include "Optimum.h"
#include "Nearer.h"

int main()
{
  std::vector<int> numbers{ 91, 18, 92, 22, 13, 43 };

  int number_to_search_for {};
  std::cout << "Please enter a number: ";
  std::cin >> number_to_search_for;

  std::cout << "The number nearest to " << number_to_search_for << " is "
            << *find_optimum(numbers, Nearer{ number_to_search_for }) << std::endl;
}
