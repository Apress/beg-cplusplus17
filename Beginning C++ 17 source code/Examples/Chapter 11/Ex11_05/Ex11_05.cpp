// Allowing method chaining by returning a reference to this
#include <iostream>
#include "Box.h"

int main()
{
  Box myBox {3.0, 4.0, 5.0};
  std::cout << "myBox dimensions are " << myBox.getLength() 
            << " by " << myBox.getWidth() 
            << " by " << myBox.getHeight() << std::endl;

  // Method chaining: set all dimensions of a Box in one statement:
  myBox.setLength(-20.0).setWidth(40.0).setHeight(10.0);
  std::cout << "myBox dimensions are now " << myBox.getLength() // 3 (unchanged: -20 was ignored)
            << " by " << myBox.getWidth()                       // by 40
            << " by " << myBox.getHeight() << std::endl;        // by 10
}
