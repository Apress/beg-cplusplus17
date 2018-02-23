// Debugging using preprocessing directives
#include <iostream>
#include <cstdlib>                       // For random number generator
#include <ctime>                         // For time function
#include "functions.h"

#define TESTRANDOM

// Function to generate a random integer 0 to count-1
size_t random(size_t count)
{
	return static_cast<size_t>(std::rand() / (RAND_MAX / count + 1));
}

int main()
{
  const int a{10}, b{5};               // Some arbitrary values
  int result{};                        // Storage for results

  const size_t num_functions {3};
  std::srand(static_cast<unsigned>(std::time(nullptr))); // Seed random generator

  // Select function at random
  for (size_t i{}; i < 5; i++)
  {
    size_t select = random(num_functions); // Generate random number (0 to num_functions-1)

#ifdef TESTRANDOM
    std::cout << "Random number = " << select << ' ';
    if (select >= num_functions)
    {
      std::cout << "Invalid random number generated!" << std::endl;
      return 1;
    }
#endif

    switch (select)
    {
      case 0: result = fun::sum(a, b); break;
      case 1: result = fun::product(a, b); break;
      case 2: result = fun::difference(a, b); break;
    }
    
    std::cout << "result = " << result << std::endl;
  }
}
