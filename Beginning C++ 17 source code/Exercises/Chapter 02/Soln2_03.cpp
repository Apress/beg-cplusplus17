// Exercise 2-3. Converting a length in inches to feet-and-inches.
#include <iostream>

int main()
{
  const int inches_per_foot {12};

  long length_inches {};

  std::cout << "This program converts inches into feet-and-inches.\n";
  std::cout << "Please enter the number of inches: ";
  std::cin >> length_inches;

  const long feet {length_inches / inches_per_foot};
  const long inches {length_inches % inches_per_foot};

  std::cout << "In " << length_inches << " inches there are "
            << feet << " feet and " << inches << " inch(es)." << std::endl;
}