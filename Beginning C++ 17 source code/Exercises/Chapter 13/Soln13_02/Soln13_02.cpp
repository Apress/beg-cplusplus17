// Exercise 13-2 The who() function for the base class has the protected access specifier,
// so we ensure the derived classes allow public access to the who() function. 

#include "Animals.h"

int main()
{
  Lion myLion{"Leo", 400};
  Aardvark myAardvark{"Algernon", 50};
  myLion.who();
  myAardvark.who();
}