#ifndef BOX_H
#define BOX_H
#include <iostream>

class Box
{
protected:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  Box() = default;
  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}

  // Uncomment the virtual keyword to make destruction work as it should
  /*virtual*/ ~Box() { std::cout << "Box destructor called" << std::endl; }
  
  // Function  to  show  the  volume of  an object
  void showVolume() const
  {
    std::cout << "Box usable volume is " << volume() << std::endl;
  }

  // Function  to  calculate the  volume of  a Box object
  virtual double volume()  const { return length*width*height; }
};
#endif
