// Exercise 5-1 Squaring odd numbers
#include <iostream>
#include <iomanip>

int main()
{
  int limit {};
  std::cout << "Enter the upper limit for squared odd numbers: ";
  std::cin >> limit;
  for (int i {1}; i <= limit; i += 2)
  {
    std::cout << std::setw(4) << i << " squared is " << std::setw(8) << i * i << std::endl;
  }
}