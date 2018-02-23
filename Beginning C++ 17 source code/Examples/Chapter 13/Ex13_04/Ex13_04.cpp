// Inheriting constructors
#include <iostream>
#include "Box.h"                 // For the Box class
#include "Carton.h"              // For the Carton class

int main()
{
// Carton cart;                     // Does not compile: default constructor is not inherited!
  Carton cube{4.0};                                        // Calls inherited constructor
  
  std::cout << std::endl;
  Carton cartcopy { cube };                                // Calls default copy constructor
  
  std::cout << std::endl;
  Carton carton {1.0, 2.0, 3.0};                           // Calls inherited constructor
  
  std::cout << std::endl;
  Carton candyCarton (50.0, 30.0, 20.0, "Thin cardboard"); // Calls Carton class constructor
}
