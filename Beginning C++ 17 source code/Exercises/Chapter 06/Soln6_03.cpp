// Exercise 6-3. Storing numbers in a dynamic array
#include <iostream>
#include <iomanip>
#include <cmath>

int main()
{
  size_t n {};
  std::cout << "Enter the number of array elements: ";
  std::cin >> n;
  auto* values = new double[n];
  for (size_t i {}; i < n; ++i)
    *(values+i) = 1.0 / ((i + 1)*(i + 1));

  double sum {};
  for (size_t i {}; i < n; ++i)
    sum += values[i];

  std::cout << "The result is " << std::setprecision(15) << std::sqrt(6.0 * sum) << std::endl;
  
  delete[] values;                                              // Don't forget to free the memory!
}