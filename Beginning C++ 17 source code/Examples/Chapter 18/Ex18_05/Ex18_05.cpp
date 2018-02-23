// Exercising the use of stateless lambda expressions as callback functions
#include <iostream>
#include <string>
#include <string_view>
#include "Optimum.h"

int main()
{
  std::vector<int> numbers{ 91, 18, 92, 22, 13, 43 };
  std::cout << "Minimum element: " << *find_optimum(numbers, [](int x, int y) { return x < y; }) << std::endl;
  std::cout << "Maximum element: " << *find_optimum(numbers, [](int x, int y) { return x > y; }) << std::endl;

  // Define nameless comparison functions for strings:
  auto alpha = [](std::string_view x, std::string_view y) { return x > y; };
  auto longer = [](std::string_view x, std::string_view y) { return x.length() > y.length(); };
  
  std::vector<std::string> names{ "Moe", "Larry", "Shemp", "Curly", "Joe", "Curly Joe" };
  std::cout << "Alphabetically last name: " << *find_optimum(names, alpha) << std::endl;
  std::cout << "Longest name: " << *find_optimum(names, longer) << std::endl;
}