// Overloaded const and non-const member functions
#include <iostream>
#include "Box.h"

int main()
{
  Box box;
  box.length() = 2;                        // References can be used to the right of an assignment
  std::cout << box.length() << std::endl;  // Prints 2
  
  const Box constBox;
// constBox.length() = 2;                  // Does not compile: good!
  std::cout << constBox.length() << std::endl;
}
