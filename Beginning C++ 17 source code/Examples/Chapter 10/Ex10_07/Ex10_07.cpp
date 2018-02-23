// Using functions in a namespace
#include <iostream>
#include <vector>

#include "compare.h"

using compare::max;                    // Using declaration for max


int main()
{
  using compare::min;                  // Using declaration for min
  
  std::vector<double> data{1.5, 4.6, 3.1, 1.1, 3.8, 2.1};
  std::cout << "Minimum double is " << min(data) << std::endl;
  std::cout << "Maximum double is " << max(data) << std::endl;
}
