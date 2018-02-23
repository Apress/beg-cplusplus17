// Finding  maximum and minimum values for data types
#include <limits>
#include <iostream>

int main()  
{
  std::cout << "The range for type short is from "
            << std::numeric_limits<short>::min() << " to "
            << std::numeric_limits<short>::max()  << std::endl;
  std::cout << "The range for type int is from "
            << std::numeric_limits<int>::min() << " to "
            << std::numeric_limits<int>::max() << std::endl;
  std::cout << "The range for type long is from "
            << std::numeric_limits<long>::min()<< " to "
            << std::numeric_limits<long>::max() << std::endl;
  std::cout << "The range for type float is from "
            << std::numeric_limits<float>::min() << " to "
            << std::numeric_limits<float>::max() << std::endl;
  std::cout << "The positive range for type double is from "
            << std::numeric_limits<double>::min() << " to "
            << std::numeric_limits<double>::max() << std::endl;
  std::cout << "The positive range for type long double is from "
            << std::numeric_limits<long double>::min() << " to "
            << std::numeric_limits<long double>::max() << std::endl;
}