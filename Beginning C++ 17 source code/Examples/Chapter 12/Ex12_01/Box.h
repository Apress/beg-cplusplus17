// Box.h	
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
  // Constructors
  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}

  Box() = default;                                                     // No-arg constructor

  double volume() const                                  // Function to calculate the volume
  {
    return length*width*height;
  }

  // Accessors
  double getLength() const { return length; }
  double getWidth() const { return width; }
  double getHeight() const { return height; }

  bool operator<(const Box& aBox) const                               // Less-than operator
  {
    return volume() < aBox.volume();
  }
};
#endif
