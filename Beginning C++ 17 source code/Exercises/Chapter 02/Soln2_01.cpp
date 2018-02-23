// Exercise 2-1. Calculate the area of a circle of given radius. 
// The value of pi is constant, and should not be changed within the program,
// so we recognize this by declaring it as a const.
// We declare the circle's area as const as well: 
// once initialized the value of this variable should never change.

#include <iostream>

int main()
{
  const float pi {3.1415926f};           // Initialize constant variable

  std::cout << "This program will compute the area of a circle." << std::endl
            << "It uses an approximation of pi equal to " << pi << "." << std::endl;

  float radius {};
  std::cout << "Please enter the radius: ";
  std::cin >> radius;

  const auto areaOfCircle = pi * radius * radius;

  std::cout << "\nThe area of the circle is " << areaOfCircle << " square units." << std::endl;
}