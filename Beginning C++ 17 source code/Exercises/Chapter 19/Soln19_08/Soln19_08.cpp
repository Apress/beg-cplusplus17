// Exercise 19-8 Parallel version of 19-7
#include <iostream>
#include <cstdlib>                       // For random number generator
#include <ctime>                         // For time function
#include <algorithm>
#include <vector>
#include <execution>

int main()
{
  std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed random generator

  const size_t num_numbers = 1'000'000;
  std::vector<int> numbers(num_numbers);

  // Why not use an algorithm as well to generate the random numbers!!
  std::generate(begin(numbers), end(numbers), std::rand);	// Careful: it is implementation-defined whether or not std::rand() 
                                                            // can be called concurrently from multiple threads...
  // Algorithm number two
  std::sort(std::execution::par, begin(numbers), end(numbers));

  // And number three; this time combined with the remove-erase idiom (or unique-erase, if you will)
  numbers.erase(std::unique(std::execution::par, begin(numbers), end(numbers)), end(numbers));	// Parallel version may not compile in Visual C++...

  std::cout << "Number of unique numbers: " << numbers.size() << std::endl;
}
