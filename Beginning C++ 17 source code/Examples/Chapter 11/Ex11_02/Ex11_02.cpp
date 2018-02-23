// Problems of implicit object conversions
#include <iostream>
#include "Cube.h"
int main()
{
  Cube box1 {7.0};
  Cube box2 {3.0};
  if (box1.hasLargerVolumeThan(box2))
    std::cout << "box1 is larger than box2." << std::endl;
  else
    std::cout << "Volume of box1 is less than or equal to that of box2." << std::endl;

  std::cout << "volume of box1 is " << box1.volume() << std::endl;
  if (box1.hasLargerVolumeThan(50.0))
    std::cout << "Volume of box1 is greater than 50"<< std::endl;
  else
    std::cout << "Volume of box1 is less than or equal to 50"<< std::endl;

}
