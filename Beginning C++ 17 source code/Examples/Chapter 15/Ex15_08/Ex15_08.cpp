// Exceptions may result in resource leaks!
#include <iostream>
#include <cmath>                    // For std::sqrt()
#include "MyTroubles.h"

double DoComputeValue(double);            // A function to compute a single value
double* ComputeValues(size_t howMany);    // A function to compute an array of values

int main() 
{
  try
  {
    double* values = ComputeValues(10000);
    // we won't be making it this far, unfortunately...
    delete[] values;
  }
  catch (const Trouble&)
  {
    std::cout << "No worries: I've caught it!" << std::endl;
  }
}

double* ComputeValues(size_t howMany)
{
  double* values = new double[howMany];
  for (size_t i = 0; i < howMany; ++i)
    values[i] = DoComputeValue(i);
  return values;
}

double DoComputeValue(double value) 
{
  if (value < 100)
    return std::sqrt(value);   // Return the square root of the input value
  else
    throw Trouble{"The trouble with trouble is, it starts out as fun!"}; 
}
