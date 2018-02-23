// Creating and including your own header file
#include <iostream>
#include <iomanip>

#include "Power.h"

int main()
{
  for (int i {-3}; i <= 3; ++i)     // Calculate powers of 8 from -3 to +3
    std::cout << std::setw(10) << power(8.0, i);

  std::cout << std::endl;
}