
//#define TESTFUNCTION                 // Uncomment to get trace output

#ifdef TESTFUNCTION
#include <iostream>                    // Only required for trace output...
#endif

#include "functions.h"

// Definition of the function sum
int fun::sum(int x, int y)
{
#ifdef TESTFUNCTION
  std::cout << "Function sum called." << std::endl;
#endif

  return x + y;
}

// Definition of the function product 
int fun::product(int x, int y)
{
#ifdef TESTFUNCTION
  std::cout << "Function product called." << std::endl;
#endif

  return x * y;
}

// Definition of the function difference 
int fun::difference(int x, int y)
{
#ifdef TESTFUNCTION
  std::cout << "Function difference called." << std::endl;
#endif

  return x - y;
}
