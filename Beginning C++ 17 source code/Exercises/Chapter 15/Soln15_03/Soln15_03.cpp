// Exercise 15-3 Using exceptions to signal index-out-of-bounds errors.
#include <iostream>
#include <memory>
#include <cstdlib>                                 // For random number generator
#include <ctime>                                   // For time function
#include "Truckload.h"

// Function to generate integral random box dimensions from 1 to max_size
inline double random(double max_size)
{
  return 1.0 + rand() / (RAND_MAX / max_size + 1);
}

int main()
{
  const double dimLimit {99.0};             // Upper limit on Box dimensions
  std::srand((unsigned) std::time(0));      // Initialize the random number generator
  Truckload load;
  const size_t boxCount {20};               // Number of Box object to be created

  // Create boxCount Box objects
  for (size_t i {}; i < boxCount; ++i)
    load.addBox(std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));

  std::cout << "The boxes in the Truckload are:\n";
  std::cout << load;

  try
  {
    std::cout << "The truckload contains the following boxes: " << std::endl;
	for (size_t i = 0; i < 100; ++i)
	{
	  std::cout << load[i] << std::endl;
	}
  }
  catch (std::exception& caughtException)
  {
    std::cerr << "Oops: " << caughtException.what() << std::endl;
  }
}
