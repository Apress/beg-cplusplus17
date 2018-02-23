// Exercise 12-6
// Adding an assignment operator for Truckload
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
  // Initialize the random number generator
  std::srand(static_cast<unsigned>(std::time(nullptr)));
  Truckload load;
  const size_t boxCount {20};               // Number of Box object to be created

  // Create boxCount Box objects
  for (size_t i {}; i < boxCount; ++i)
    load.addBox(std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));

  std::cout << "The boxes in the Truckload are:\n";
  std::cout << load;

  Truckload copied;
  copied = load;		// Use copy assignment
 
  std::cout << "The boxes in the copied Truckload are:\n";
  std::cout << copied;
}
