// Defining and accessing static constants
#include <iostream>
#include "CylindricalBox.h"

int main()
{
  const CylindricalBox bigBox{ 1.23f, CylindricalBox::maxHeight, CylindricalBox::defaultMaterial };
  std::cout << "The volume of bigBox is " << bigBox.volume() << std::endl;
}
