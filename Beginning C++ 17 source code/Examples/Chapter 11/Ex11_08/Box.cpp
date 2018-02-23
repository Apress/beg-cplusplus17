#include <iostream>
#include "Box.h"

// Constructor definition
Box::Box(double lv, double wv, double hv)
 : length{lv}, width{wv}, height{hv}
{
}

// Function to calculate the volume of a box
double Box::volume() const
{
  return length * width * height;
}

// Function to print the volume of a Box to std::cout
void Box::printVolume() const
{
  // Count how many times printVolume() is called using a mutable member in a const function
  std::cout << "The volume of this box is " << volume() << std::endl;
  std::cout << "printVolume() has been called " << ++count << " time(s)" << std::endl;
}
