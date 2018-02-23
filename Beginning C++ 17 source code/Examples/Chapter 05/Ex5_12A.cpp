// Allocating an array at runtime
// This example does not work with some compilers (such as Visual C++)
// because dynamic arrays is not standard C++ (it is valid C though).
#include  <iostream>

int main()
{
  size_t count {};
  std::cout << "How many heights will you enter? ";
  std::cin >> count;
  unsigned int height[count];               // Create the array of count elements

  // Read the heights. While doing so, accumulate the sum of the heights as well.
  unsigned int total {};
  size_t entered {};
  while (entered < count)
  {
    std::cout <<"Enter a height: ";
    std::cin >> height[entered];
    if (height[entered])                     // Make sure value is positive
    {
      total += height[entered++];
    }
    else
    {
      std::cout << "A height must be positive - try again.\n";
    }
  }
  
  std::cout << "The average height is " << total/count << std::endl;
}

