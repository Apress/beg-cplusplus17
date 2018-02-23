// Exercise 5-08. Generate 93 Fibonacci numbers stored in an array.
// 93 was not an arbitrary choice for the number  of Fibonacci numbers.
// Fibonacci number grow fairly rapidly.
// 93 is the most that are possible with type unsigned long long.

#include <iostream>
#include <array>

int main()
{
  const size_t n {93};
  std::array<unsigned long long, n> fib;
  fib[0] = fib[1] = 1UL;
  for (size_t i {2}; i < n; ++i)
    fib[i] = fib[i - 1] + fib[i - 2];

  std::cout << "The first " << n << " Fibonacci numbers are:\n";
  for (auto number : fib)
  {
    std::cout << number << std::endl;
  }
}
