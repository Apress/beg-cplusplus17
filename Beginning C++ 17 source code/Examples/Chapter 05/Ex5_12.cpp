// Allocating an array at runtime
// This example does not work with some compilers (such as Visual C++)
// because dynamic arrays is not standard C++ (it is valid C though).
#include <iostream>
#include <iomanip>      // for std::setprecision()

int main()
{
  size_t count {};
  std::cout << "How many heights will you enter? ";
  std::cin >> count;
  int height[count];                         // Create the array of count elements

  // Read the heights
  size_t entered {};
  while (entered < count)
  {
    std::cout <<"Enter a height: ";
    std::cin >> height[entered];
    if (height[entered] > 0)                 // Make sure value is positive
    {
      ++entered;
    }
    else
    {
      std::cout << "A height must be positive - try again.\n";
    }
  }

  // Calculate the sum of the heights
  unsigned int total {};
  for (size_t i {}; i < count; ++i)
  {
    total += height[i];
  }
  std::cout << std::fixed << std::setprecision(1);
  std::cout << "The average height is " << static_cast<float>(total) / count << std::endl;
}
