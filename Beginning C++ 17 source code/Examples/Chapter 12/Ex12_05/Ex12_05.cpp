// Using the addition operator for Box ojects
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

  size_t first {}; 	                   // Index of first Box object of pair 
  size_t second {};  	               // Index of second Box object of pair
  double minVolume {(boxes[first] + boxes[second]).volume()};

  for (size_t i {}; i < boxCount - 1; ++i)
  {
    for (size_t j {i + 1}; j < boxCount; j++)
    {
      if (boxes[i] + boxes[j] < minVolume)
      {
        first = i;
        second = j;
        minVolume = (boxes[i] + boxes[j]).volume();
      }
	}
  }

  std::cout << "The two boxes that sum to the smallest volume are: "
            << boxes[first] << " and " << boxes[second];
  std::cout << "\nThe volume of the first box is " << boxes[first].volume();
  std::cout << "\nThe volume of the second box is " << boxes[second].volume();
  std::cout << "\nThe sum of these boxes is " << (boxes[first] + boxes[second]);
  std::cout << "\nThe volume of the sum is " << minVolume << std::endl;
}
