// Box.h - defines Box class
#ifndef BOX_H
#define BOX_H
#include <iostream>                         // For standard streams
#include <iomanip>                          // For stream manipulators

class Box
{
protected:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  // Constructors
  Box(double lv, double wv, double hv) 
    : length {lv}, width {wv}, height {hv} 
  {
    std::cout << "Box(double, double, double) called.\n";
  }

  explicit Box(double side) 
    : Box {side, side, side} 
  { 
    std::cout << "Box(double) called.\n";
  }
  
  Box() { std::cout << "Box() called.\n"; }   // No-arg constructor

  double volume() const                     // Function to calculate the volume
  {
    return length*width*height;
  }

  // Accessors
  double getLength() const { return length; }
  double getWidth()  const { return width; }
  double getHeight() const { return height; }

  friend std::ostream& operator<<(std::ostream& stream, const Box& box);
};

// Stream output for Box objects
inline std::ostream& operator<<(std::ostream& stream, const Box& box)
{
  return stream << " Box(" 
    << std::setw(2) << box.length << ','
    << std::setw(2) << box.width <<  ','
    << std::setw(2) << box.height << ')';
}
#endif
