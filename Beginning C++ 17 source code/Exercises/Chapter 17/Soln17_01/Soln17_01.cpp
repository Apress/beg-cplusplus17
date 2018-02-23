// Exercise 17-1 Define move operators for the Truckload class
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

  Truckload moveConstructedLoad(std::move(load));

  std::cout << "The boxes in the move constructed Truckload are:\n";
  std::cout << moveConstructedLoad;

  Truckload moveAssignedLoad;
  moveAssignedLoad = std::move(moveConstructedLoad);
  
  std::cout << "The boxes in the move assigned Truckload are:\n";
  std::cout << moveAssignedLoad;
}
