// Throwing exceptions in nested try blocks
#include <iostream>

void throwIt(int i)
{
  throw i;                             // Throws the parameter value
}

int main()
{
  for (int i {}; i <= 5; ++i)
  {
    try
    {
      std::cout << "outer try:\n";
      if (i == 0)
        throw i;                       // Throw int exception

      if (i == 1)
        throwIt(i);                    // Call the function that throws int

      try
      {                                // Nested try block
        std::cout << "inner try:\n";
        if (i == 2)
          throw static_cast<long>(i);  // Throw long exception

        if (i == 3)
          throwIt(i);                  // Call the function that throws int
      }                                // End nested try block 
      catch (int n)
      {
        std::cout << "Catch int for inner try. " << "Exception " << n << std::endl;
      }

      std::cout << "outer try:\n";
      if (i == 4)
        throw i;                       // Throw int
      throwIt(i);                      // Call the function that throws int
    }
    catch (int n)
    {
      std::cout << "Catch int for outer try. " << "Exception " << n << std::endl;
    }
    catch (long n)
    {
      std::cout << "Catch long for outer try. " << "Exception " << n << std::endl;
    }
  }
}
