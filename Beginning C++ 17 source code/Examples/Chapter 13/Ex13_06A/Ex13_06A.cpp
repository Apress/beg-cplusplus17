// Ex13_05A
// Using multiple inheritance
#include <iostream>
#include "CerealPack.h"             // For the CerealPack class

int main() 
{
  CerealPack cornflakes {8.0, 3.0, 10.0, "Cornflakes"};

  std::cout << "cornflakes volume is " << cornflakes.Carton::volume() << std::endl
            << "cornflakes weight is " << cornflakes.Contents::getWeight() << std::endl;
}
