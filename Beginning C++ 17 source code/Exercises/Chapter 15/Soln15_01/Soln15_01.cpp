// Exercise 15-1 Throwing and catching CurveBalls
#include "CurveBall.h"
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
  if (random(100) < 25)
    throw CurveBall{};
}

int main() 
{
  std::srand(static_cast<unsigned>(std::time(0)));  // Seed random number generator
  size_t number {1000};                             // Number of loop iterations
  size_t exceptionCount {};                         // Count of exceptions thrown

  for (size_t i {}; i < number; ++i)
  {
    try
    {
      sometimes();
    }
    catch (const CurveBall&)
    {
      exceptionCount++;
    }
  }
  
  std::cout << "CurveBall exception thrown " << exceptionCount << " times out of " << number << ".\n";
}