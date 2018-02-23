// Rethrowing exceptions
#include <iostream>
#include <typeinfo>
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
      catch (const Trouble& t)
      {
        if (typeid(t) == typeid(Trouble))
          std::cout << "Trouble object caught in inner block: " << t.what() << std::endl;
        else
          throw;		                          // Rethrow current exception
//          throw t;		                        // Throw current exception
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