// Exercise 18-3. Comparing two sorting algorithms

#include <iostream>
#include <iomanip>
#include <functional>
#include <cctype>         // For std::tolower()
#include <cmath>          // For std::abs()
#include <cstdlib>        // For basic random number generation (std::rand() and srand())
#include <ctime>          // For std::time() (used to seed the pseudo-random number generator)
#include "Sort.h"

// Function to generate a random integer 1 to max (both inclusive)
int random(int max) 
{
  return 1 + rand() / (RAND_MAX / max + 1);
}

std::vector<int> generateRandomNumbers(unsigned number)
{
  std::vector<int> result;
  for (unsigned i = 0; i < number; ++i)
    result.push_back(random(100));
  return result;
}

int main()
{  
  unsigned count {};
  auto counting_less = [&count](int x, int y) { ++count; return x < y; };
  
  const auto sizes = { 500u, 1'000u, 2'000u, 4'000u };
  for (auto size : sizes)
  {
    const auto numbers = generateRandomNumbers(size);
	
	count = 0;                                // Reset the count
	auto copy = numbers;                      // Ensure both sorrting algorithms work on exact same random sequence
	quicksort(copy, counting_less);
	const auto quicksort_count = count;
	
	count = 0;                                // Repeat for bubble sort algorithm
	copy = numbers;
	bubbleSort(copy, counting_less);
	const auto bubbleSort_count = count;
	
	std::cout << "Number of comparisons for " << size << " elements:\n"
		<< " - quicksort: " << quicksort_count 
		<< " (n*log(n): " << static_cast<unsigned>(size * std::log2(size)) << ")\n"
		<< " - bubble sort: " << bubbleSort_count 
		<< " (n*n: " << (size * size) << ")\n" 
		<< std::endl;
  }
}