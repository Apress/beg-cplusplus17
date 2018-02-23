// Implementing operator+=() in terms of operator+()
#include <iostream>
#include <vector>
#include <cstdlib>			               // For random number generator
#include <ctime>			               // For time function
#include "Box.h"

// Function to generate integral random box dimensions from 1 to max_size
inline double random(double max_size)
{
  return 1 + static_cast<int>(std::rand() / (RAND_MAX / max_size + 1));
}

int main() 
{
  const double dimLimit {99.0}; 	   // Upper limit on Box dimensions
  // Initialize the random number generator
  std::srand(static_cast<unsigned>(std::time(nullptr)));

  const size_t boxCount {20}; 	       // Number of Box object to be created
  std::vector<Box> boxes; 	           // Vector of Box objects

  // Create 20 Box objects
  for (size_t i {}; i < boxCount; ++i)
    boxes.push_back(Box {random(dimLimit), random(dimLimit), random(dimLimit)});

  Box sum{0, 0, 0};              // Start from an empty Box
  for (const auto& box : boxes)  // And then add all randomly generated Box objects
    sum += box;
  
  std::cout << "The sum of " << boxCount << " random Boxes is " << sum << std::endl;
}
