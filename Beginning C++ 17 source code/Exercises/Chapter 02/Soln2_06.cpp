// Exercise 2-6. Finding the largest of two integers without comparing them.
// The expressions depend on the fact that smaller/larger will be 0 with integer arithmetic
// whereas larger/smaller will be some positive non-zero integer.
#include <iostream>

int main()
{
  long a {};
  long b {};

  std::cout << "Enter a positive integer: ";
  std::cin >> a;
  std::cout << "Enter another different positive integer: ";
  std::cin >> b;

  // The trick is to find arithmetic expressions for each of the larger
  // and the smaller of the two integers
  const long larger {(a * (a / b) + b * (b / a)) / (a / b + b / a)};
  const long smaller {(b * (a / b) + a * (b / a)) / (a / b + b / a)};
  std::cout << "The larger integer is " << larger << ".\n"
            << "The smaller integer is " << smaller << '.' << std::endl;
}