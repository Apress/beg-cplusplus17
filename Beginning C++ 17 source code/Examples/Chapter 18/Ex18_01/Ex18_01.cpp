// Exercising pointers to functions
#include <iostream>

long sum(long a, long b);                               // Function prototype
long product(long a, long b);                           // Function prototype

int main()
{
  long(*do_it)(long, long) {};	                        // Pointer to function

  do_it = product;
  std::cout << "3 * 5 = " << do_it(3, 5) << std::endl;  // Call product thru a pointer

  do_it = sum;                                          // Reassign pointer to sum()
  std::cout << "3 * (4+5) + 6 = " 
            << do_it(product(3, do_it(4, 5)), 6) << std::endl;  // Call thru a pointer twice
}

// Function to multiply two values
long product(long a, long b) { return a * b; }

// Function to add two values
long sum(long a, long b) { return a + b; }
