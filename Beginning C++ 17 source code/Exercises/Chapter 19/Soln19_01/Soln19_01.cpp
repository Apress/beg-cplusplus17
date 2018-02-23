// Exercise 19-1 Rework the Truckload class usign Standard containers
#include <iostream>
#include <memory>
#include <cstdlib>                                 // For random number generator
#include <ctime>                                   // For time function
#include "Truckload.h"

// Function to generate integral random box dimensions from 1 to max_size
inline double random(double max_size)
{
  return 1 + rand() / (RAND_MAX / max_size + 1);
}

int main()
{
  const double dimLimit {99.0};             // Upper limit on Box dimensions
  std::srand((unsigned) std::time(0));      // Initialize the random number generator
  Truckload load;
  const size_t boxCount {20};               // Number of Box object to be created

  // Create boxCount Box objects (one too many)
  for (size_t i {}; i < boxCount + 1; ++i)
    load.addBox(std::make_shared<Box>(random(dimLimit), random(dimLimit), random(dimLimit)));

  // Remove the middle box
  load.removeBox(load[load.getSize() / 2]);

  std::cout << "The boxes in the Truckload are:\n";
  std::cout << load;

  // Rule of zero: even though we haven't defined any copy/move members,
  // defaults are generated for us that work correctly now!
  Truckload moveConstructedLoad(std::move(load));

  std::cout << "The boxes in the move constructed Truckload are:\n";
  std::cout << moveConstructedLoad;

  Truckload moveAssignedLoad;
  moveAssignedLoad = std::move(moveConstructedLoad);
  
  std::cout << "The boxes in the move assigned Truckload are:\n";
  std::cout << moveAssignedLoad;
}
