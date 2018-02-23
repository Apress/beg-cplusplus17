// Creating functions with internal linkage.
// You cannot call the compute() from this translation unit.
// To demonstrate this, try uncommenting its prototype and call inside main() below...

#include <iostream>
#include <iomanip>

double power(double x, int n);
// double compute(double, unsigned n);

int main()
{
  for (int i {-3}; i <= 3; ++i)     // Calculate powers of 8 from -3 to +3
    std::cout << std::setw(10) << power(8.0, i);

  // unsigned exponent = 8;
  // std::cout << compute(2.0, exponent) << std::endl;
	
  std::cout << std::endl;
}
