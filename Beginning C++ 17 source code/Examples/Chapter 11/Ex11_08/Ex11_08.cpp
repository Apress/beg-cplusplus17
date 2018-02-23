// Defining mutable member variables that can be modified within const member functions
#include <iostream>
#include "Box.h"

int main()
{
  Box myBox {3.0, 4.0, 5.0};
  myBox.printVolume();
  
  myBox.setHeight(55.5);
  myBox.printVolume();
  
  // Even for constant Boxes mutable member variables can be modified:
  const Box constBox{ 1.0, 2.0, 3.0 };
  constBox.printVolume();
  constBox.printVolume();
}