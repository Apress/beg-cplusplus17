#include <iostream>
#include "Box.h"

// Constructor definition
Box::Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv}
{
  ++objectCount;
  std::cout << "Box constructor 1 called." << std::endl;
}

Box::Box(double side) : Box {side, side, side}  // Constructor for a cube
{
  std::cout << "Box constructor 2 called." << std::endl;
}

Box::Box()                                      // Default constructor
{
  ++objectCount;
  std::cout << "Default Box constructor called." << std::endl;
}

Box::Box(const Box& box)                        // Copy constructor
  : length {box.length}, width {box.width}, height {box.height}
{
  ++objectCount; 
  std::cout << "Box copy constructor called." << std::endl;
}

// Function to calculate the volume of a box
double Box::volume() const
{
  return length*width*height;
}
