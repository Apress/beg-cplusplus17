// Exercise 15-2 Throwing and catching CurveBalls and throwing TooManyExceptions
#include "CurveBall.h"
#include "TooManyExceptions.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

// Function to generate a random integer 0 to count-1
size_t random(size_t count)
{
  return static_cast<size_t>(rand() / (RAND_MAX / count + 1));
}

// Throw a CurveBall exception 25% of the time
void sometimes()
{
  if (random(4) == 0)
    throw CurveBall{};
}

// This program will terminate abnormally when the TooManyExceptions exception is thrown.
int main()
{
  std::srand(static_cast<unsigned>(std::time(0)));            // Seed random number generator
  size_t number {1000};                          // Number of loop iterations
  size_t exceptionCount {};                      // Count of exceptions thrown

  for (size_t i {}; i < number; ++i)
  {
    try
    {
      sometimes();
    }
    catch(CurveBall& e)
    {
      std::cout << e.what() << std::endl;
    
      if (++exceptionCount > 10)
        throw TooManyExceptions{};
    }
  }
}