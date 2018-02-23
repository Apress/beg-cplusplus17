// Using an externally defined variable
// Add extern or comment/uncomment the lines below to fix the linker error...
#include <iostream>
#include <iomanip>

double power(double x, int n);      // Declaration of an external power() function
int power_range;                    // Not an unreasonable first attempt, right?
// extern int power_range;          // Declaration of an externally defined variable

int main()
{
  for (int i {-power_range}; i <= power_range; ++i)     // Calculate powers of 8
    std::cout << std::setw(10) << power(8.0, i);

  std::cout << std::endl;
}
