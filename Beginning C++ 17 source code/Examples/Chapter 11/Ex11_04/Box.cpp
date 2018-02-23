#include <iostream>
#include "Box.h"

// Constructor definition
Box::Box(double lv, double wv, double hv)
 : length{lv}, width{wv}, height{hv}
{
}

// Function to calculate the volume of a box
double Box::volume()
{
  return length * width * height;
}
