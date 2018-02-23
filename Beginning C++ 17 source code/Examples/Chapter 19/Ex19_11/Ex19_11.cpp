// Your first algorithms: std::min_element() and max_element()
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  std::vector<int> numbers{ 91, 18, 92, 22, 13, 43 };
  std::cout << "Minimum element: " 
            << *std::min_element(begin(numbers), end(numbers)) << std::endl;
  std::cout << "Maximum element: " 
            << *std::max_element(begin(numbers), end(numbers)) << std::endl;

  int number_to_search_for {};
  std::cout << "Please enter a number: ";
  std::cin >> number_to_search_for;

  auto nearer { [=](int x, int y) {
    return std::abs(x - number_to_search_for) < std::abs(y - number_to_search_for);
  }};
  
  std::cout << "The number nearest to " << number_to_search_for << " is "
            << *std::min_element(begin(numbers), end(numbers), nearer) << std::endl;
  std::cout << "The number furthest from " << number_to_search_for << " is "
            << *std::max_element(begin(numbers), end(numbers), nearer) << std::endl;
}
