// Catching any exception
#include <iostream>
#include <typeinfo>         // For use of typeid()
#include "MyTroubles.h"

int main()
{
  Trouble trouble;
  MoreTrouble moreTrouble;
  BigTrouble bigTrouble;

  for (int i {}; i < 7; ++i)
  {
    try
    {
      try
      {
        if (i == 3)
          throw trouble;
        else if (i == 5)
          throw moreTrouble;
        else if(i == 6)
          throw bigTrouble;
      }
      catch (...)                               // Catch any exception
      {
        std::cout << "We caught something! Let's rethrow it. " << std::endl;
        throw;		                            // Rethrow current exception
      }
    }
    catch (const Trouble& t)
    {
      std::cout << typeid(t).name() << " object caught in outer block: "
                << t.what() << std::endl;
    }
    std::cout << "End of the for loop (after the catch blocks) - i is " << i << std::endl;
  }
}