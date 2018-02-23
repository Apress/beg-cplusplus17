#ifndef BOX_H
#define BOX_H

class Box
{
private:
  double length;
  double width;
  double height;

public:
  // Constructors
  Box(double lv = 1.0, double wv = 1.0, double hv = 1.0);

  double volume() const;                        // Function to calculate the volume of a box

  friend double surfaceArea(const Box& aBox);   // Friend function for the surface area
};
#endif
