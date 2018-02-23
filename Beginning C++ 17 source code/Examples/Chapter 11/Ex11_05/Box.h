#ifndef BOX_H
#define BOX_H

class Box
{
private:
  double length{1.0};
  double width{1.0};
  double height{1.0};

public:
  // Constructors
  Box() = default;
  Box(double length, double width, double height);
  
  double volume();               // Function to calculate the volume of a box

  // Functions to provide access to the values of member variables
  double getLength() { return length; }
  double getWidth()  { return width; }
  double getHeight() { return height; }

  // Functions to set member variable values
  Box& setLength(double lv);
  Box& setWidth(double wv);
  Box& setHeight(double hv);
};

#endif
