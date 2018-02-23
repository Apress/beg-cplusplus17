#ifndef BOX_H
#define BOX_H
#include <iostream>
#include <iomanip>
#include <algorithm>              // For max() and min() function templates

class Box
{
private:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  // Constructors
  Box(double lv, double wv, double hv)
    : length {std::max(lv, wv)}, width {std::min(lv, wv)}, height {hv} {}
  Box() = default;

  double volume() const                                    // Function to calculate the volume
  {
    return length*width*height;
  }

  // Accessors
  double getLength() const { return length; }
  double getWidth() const  { return width; }
  double getHeight() const { return height; }

  bool operator<(const Box& aBox) const;                   // Less-than operator
  bool operator<(double value) const;                      // Compare Box volume < double value
  
  Box& operator+=(const Box& aBox);                  // Function to add a Box to an existing one
  Box operator+(const Box& aBox) const;                    // Function to add two Box objects
};

// Less-than comparison for Box objects
inline bool Box::operator<(const Box& aBox) const
{
  return volume() < aBox.volume();
}

// Compare the volume of a Box object with a constant
inline bool Box::operator<(double value) const 
{
  return volume() < value;
}

// Function comparing a constant with volume of a Box object
inline bool operator<(double value, const Box& aBox)
{
  return value < aBox.volume();
}

// Operator function to add one Box to an existing Box object 
inline Box& Box::operator+=(const Box& aBox)
{
  // New object has larger length and width, and sum of heights
  length = std::max(length, aBox.length);
  width  = std::max(width, aBox.width);
  height += aBox.height;
  return *this;
}

// Operator function to add two Box objects
inline Box Box::operator+(const Box& aBox) const
{
  Box copy{*this};
  copy += aBox;      // Implemented in terms of +=
  return copy;
}

// Stream output operator
std::ostream& operator<<(std::ostream& stream, const Box& box)
{
  return stream << "Box(" 
    << std::setw(2) << box.getLength() << ','
    << std::setw(2) << box.getWidth()  << ','
    << std::setw(2) << box.getHeight() << ')';
}
#endif
