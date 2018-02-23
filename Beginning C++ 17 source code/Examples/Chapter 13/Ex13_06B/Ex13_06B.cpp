// Ex13_06B
// Using multiple inheritance
#include <iostream>
#include "CerealPack.h"             // For the CerealPack class

int main() 
{
  CerealPack cornflakes {8.0, 3.0, 10.0, "Cornflakes"};

  std::cout << "cornflakes volume is " << cornflakes.volume() << std::endl
            << "cornflakes weight is " << cornflakes.getWeight() << std::endl;
}
