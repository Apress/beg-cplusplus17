// Defining const member functions that can be called on const objects
#include <iostream>
#include "Box.h"

int main()
{
  const Box myBox {3.0, 4.0, 5.0};
  std::cout << "myBox dimensions are " << myBox.getLength() 
            << " by " << myBox.getWidth() 
            << " by " << myBox.getHeight() << std::endl;
			
  std::cout << "myBox' volume is " << myBox.volume() << std::endl;

/*
  // The setters are not const, so they cannot be called on myBox...
  myBox.setLength(-20.0);
  myBox.setWidth(40.0);
  myBox.setHeight(10.0);
*/

  // To call setters, you need to define a non-const object
  Box anotherBox;
  anotherBox.setLength(3.0);
  anotherBox.setWidth(4.0);
  anotherBox.setHeight(5.0);
  std::cout << "anotherBox dimensions are " << anotherBox.getLength()
            << " by " << anotherBox.getWidth()
            << " by " << anotherBox.getHeight() << std::endl;
}
