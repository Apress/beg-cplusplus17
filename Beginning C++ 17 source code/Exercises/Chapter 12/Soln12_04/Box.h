// Box.h
#ifndef BOX_H
#define BOX_H
#include <iostream>
#include <iomanip>
#include <algorithm>		// For std::max()

class Box
{
private:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  // Constructors
  Box(double lv, double wv, double hv) 
	: length {lv}, width {wv}, height {hv} {}

  Box() = default;                                                     // No-arg constructor

  double volume() const                                                // Function to calculate the volume
  {
    return length*width*height;
  }

  // Accessors
  double getLength() const { return length; }
  double getWidth()  const { return width; }
  double getHeight() const { return height; }
  
  operator bool() const;                                               // Conversion-to-bool operator
  bool operator!() const;                                              // Negation operator
  
  bool operator<(const Box& aBox) const;                               // Less-than operator
  bool operator<(double aValue) const;                                 // Compare Box volume < double value
};

// Conversion-to-bool operator
Box::operator bool() const
{
  return volume() != 0;
}

// Negation operator
bool Box::operator!() const
{
  return volume() == 0;
}

// Less-than comparison for Box objects
bool Box::operator<(const Box& aBox) const
{
  return volume() < aBox.volume();
}

// Compare the volume of a Box object with a constant
bool Box::operator<(double aValue) const
{
  return volume() < aValue;
}

// Function comparing a constant with volume of a Box object
bool operator<(double aValue, const Box& aBox)
{
  return aValue < aBox.volume();
}

std::ostream& operator<<(std::ostream& stream, const Box& box)
{
  stream << " Box(" << std::setw(2) << box.getLength() << ','
    << std::setw(2) << box.getWidth() << ','
    << std::setw(2) << box.getHeight() << ')';
  return stream;
}

#endif