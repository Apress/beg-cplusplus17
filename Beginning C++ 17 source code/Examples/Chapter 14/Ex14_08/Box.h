#ifndef BOX_H
#define BOX_H
#include <iostream>

class Box 
{
private:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  Box(double lv, double wv, double hv) 
    : length {lv}, width {wv}, height {hv}
  {
    std::cout << "Box constructor called for a Box of volume " << volume() << std::endl;
  }
  virtual ~Box()
  { 
    std::cout << "Box destructor called for a Box of volume " << volume() << std::endl;
  }
  
  // Function to calculate volume of a Box
  virtual double volume() const { return length * width * height; }
  
  void showVolume() const
  {
    std::cout << "The volume from inside Box::showVolume() is " << volume() << std::endl;
  }
};

#endif