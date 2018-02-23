// Throwing and catching objects in a hierarchy
#include <iostream>
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
      if (i == 3)
        throw trouble;
      else if (i == 5)
        throw moreTrouble;
      else if(i == 6)
        throw bigTrouble;
    }
    catch (const BigTrouble& t)
    {
      std::cout << "BigTrouble object caught: " << t.what() << std::endl;
    }
    catch (const MoreTrouble& t)
    {
      std::cout << "MoreTrouble object caught: " << t.what() << std::endl;
    }
    catch (const Trouble& t)
    {
      std::cout << "Trouble object caught: " << t.what() << std::endl;
    }
    std::cout << "End of the for loop (after the catch blocks) - i is " << i << std::endl;
  }
}