#include <iostream>
#include "Box.h"

// Constructor definition
Box::Box(double lv, double wv, double hv) : length {lv}, width {wv}, height{hv}
{
  std::cout << "Box constructor called." << std::endl;
}

// Function to calculate the volume of a box
double Box::volume() const
{
  return length*width*height;
}
