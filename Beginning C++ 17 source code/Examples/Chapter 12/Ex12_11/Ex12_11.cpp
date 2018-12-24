// Using the subscript operator on the left-hand side of an assignment
#include <iostream>
#include <memory>
#include <cstdlib>                                 // For random number generator
#include <ctime>                                   // For time function
#include "Truckload.cpp"

// Function to generate integral random box dimensions from 1 to max_size
inline double random(double max_size)
{
  return 1 + static_cast<int>(std::rand() / (RAND_MAX / max_size + 1));
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

  // Find the largest Box in the Truckload
  double maxVolume {};
  size_t maxIndex {};
  size_t i {};
  while (load[i])
  {
    if (load[i]->volume() > maxVolume)
    {
      maxIndex = i;
      maxVolume = load[i]->volume();
    }
    ++i;
  }

  std::cout << "\nThe largest box is: ";
  std::cout << *load[maxIndex] << std::endl;

  load.removeBox(load[maxIndex]);
  std::cout << "\nAfter deleting the largest box, the Truckload contains:\n";
  std::cout << load;
  
  load[0] = load[1];                        // Copy 2nd element to 1st
  std::cout << "\nAfter copying the 2nd element to the 1st, the list contains:\n";
  std::cout << load;

  load[1] = std::make_shared<Box>(*load[2] + *load[3]);
  std::cout << "\nAfter making the 2nd element a pointer to the 3rd plus 4th,"
                                                      " the list contains:\n";
  std::cout << load;
}
