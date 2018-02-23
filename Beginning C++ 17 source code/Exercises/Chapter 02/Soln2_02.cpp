// Exercise 2-2 This time, the user is also prompted to enter an integer that we can
// subsequently use to control the program's output. 
// Note that setprecision() doesn't alter the calculated value of areaOfCircle;
// it's only used to control how this value is output.

#include <iostream>
#include <iomanip>

int main()
{
  const double pi {3.141592653589793238};           // Initialize constant variable

  std::cout << "This program will compute the area of a circle." << std::endl
            << "It uses an approximation of pi equal to " << pi << "." << std::endl;

  double radius {};
  std::cout << "Please enter the radius: ";
  std::cin >> radius;

  int precision;
  std::cout << "Please enter the desired precision of the output (significant figures): ";
  std::cin >> precision;
  
  std::cout << std::setprecision(precision);
  
  const auto areaOfCircle = pi * radius * radius;

  std::cout << "\nThe area of the circle is " << areaOfCircle << " square units." << std::endl;
}