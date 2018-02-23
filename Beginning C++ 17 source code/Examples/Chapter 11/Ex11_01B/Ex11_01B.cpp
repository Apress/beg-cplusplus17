// Defining functions and constructors outside the class definition
#include <iostream>
#include "Box.h"

int main()
{
  Box firstBox {80.0, 50.0, 40.0};             // Create a box
  double firstBoxVolume{firstBox.volume()};    // Calculate the box  volume
  std::cout << "Volume of the first Box object is " << firstBoxVolume << std::endl;
  
  Box secondBox;                               // Uses compiler-generated default constructor
  double secondBoxVolume{secondBox.volume()};  // Calculate the box volume
  std::cout << "Volume of the second Box object is " << secondBoxVolume << std::endl;
}
