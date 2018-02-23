// Exercise 16-4 Exercising the SparseArray class template
// We create a sparse array of integers, populate 20 of its entries 
// (checking for duplicates among the randomly generated indices)
// and output the resulting index/value pairs.

#include "SparseArray.h"
#include <cstdlib>    // For std::rand() and RAND_MAX
#include <ctime>      // For std::time()
#include <iostream>

// Function to generate a random integer min to max (both inclusive)
int random(int min, int max) 
{
  return min + std::rand() / (RAND_MAX / (max - min + 1) + 1);
}

int main()
{
  const size_t count {20};                 // Number of elements to be created
  const int min_value{32};
  const int max_value{212};
  const size_t max_index{499};
  
  std::srand(static_cast<unsigned>(std::time(0)));  // Seed random number generator

  SparseArray<int> numbers;               // Create empty sparse array
  
  for (size_t i {}; i < count; ++i)       // Create count entries in numbers array
  {
	size_t index {};                      // Stores new index value

    // Must ensure that indexes after the first are not duplicates
    do
    {
      index = random(0, max_index);       // Get a random index 0 to max_index-1
    }
	while (numbers.element_exists_at(index));

    numbers[index] = random(min_value, max_value);      // Store value at new index position
  }

  for (size_t i {}; i <= max_index; ++i)       // Create count entries in numbers array
  {
    if (numbers.element_exists_at(i))
      std::cout << "Element at index " << i << " equals " << numbers.at(i) << std::endl;
  }
}