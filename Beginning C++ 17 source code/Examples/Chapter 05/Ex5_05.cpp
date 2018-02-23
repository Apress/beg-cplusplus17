// Using a while loop to calculate the sum of integers from 1 to n and n!
#include <iostream>
#include <iomanip>

int main()
{
  unsigned int limit{};
  std::cout << "This program calculates n! and the sum of the integers"
    << " up to n for values 1 to limit.\n";
  std::cout << "What upper limit for n would you like? ";
  std::cin >> limit;

  // Output column headings
  std::cout << std::setw(8) << "integer" << std::setw(8) << " sum"
            << std::setw(20) << " factorial" << std::endl;
  unsigned int n{};
  unsigned int sum{};
  unsigned long long factorial{ 1ULL };

  while (++n <= limit)
  {
    sum += n;                          // Accumulate sum to current n
    factorial *= n;                    // Calculate n! for current n
    std::cout << std::setw(8) << n << std::setw(8) << sum
      << std::setw(20) << factorial << std::endl;
  }
}
