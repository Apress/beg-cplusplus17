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
  
  // Alternate method:
  // Find the average, average difference, whether the difference
  // even or odd (0 if even, 1 if odd). The larger number is the sum
  // of the three. The smaller number is the difference between the first two.
  // The <cmath> header would have to be included for this to work.
  //
  // const long average {(a + b) / 2};
  // const long difference {std::abs(a - b)};
  // const long average_difference {difference / 2};
  // const long difference_is_odd {difference % 2};
  // const long larger {average + average_difference + difference_is_odd};
  // const long smaller {average - average_difference};
  //
  // This method should require less computation than the method described above,
  // and only uses operators and functions presented in the second chapter.
  
  std::cout << "The larger integer is " << larger << ".\n"
            << "The smaller integer is " << smaller << '.' << std::endl;
}
