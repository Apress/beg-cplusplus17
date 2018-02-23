// Exercise 19-7 Apply remove-erase idiom to remove duplicate elements
#include <iostream>
#include <cstdlib>                       // For random number generator
#include <ctime>                         // For time function
#include <algorithm>
#include <vector>

int main()
{
  std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed random generator

  const size_t num_numbers = 1'000'000;
  std::vector<int> numbers(num_numbers);

  // Why not use an algorithm as well to generate the random numbers!!
  std::generate(begin(numbers), end(numbers), std::rand);

  // Algorithm number two
  std::sort(begin(numbers), end(numbers));

  // And number three; this time combined with the remove-erase idiom (or unique-erase, if you will)
  numbers.erase(std::unique(begin(numbers), end(numbers)), end(numbers));

  std::cout << "Number of unique numbers: " << numbers.size() << std::endl;
}
