#include <iostream>
#include "Box.h"

// Constructor definition
Box::Box(double lv, double wv, double hv)
 : _length{lv}, _width{wv}, _height{hv}
{
}

// Function to calculate the volume of a box
double Box::volume() const
{
  return _length * _width * _height;
}
