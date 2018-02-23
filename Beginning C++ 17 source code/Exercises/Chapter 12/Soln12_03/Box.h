// Box.h
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
  bool operator<(double aValue) const;                     // Compare Box volume < double value
  
  Box operator+(const Box& aBox) const;                    // Function to add two Box objects
  Box operator*(unsigned n) const;                         // Post-multiply an object by an integer
  Box operator/(unsigned n) const;                         // Divide an object by an integer
  
  Box& operator+=(const Box& aBox);                        // Compound assignment operator that adds a Box
  Box& operator*=(unsigned n);                             // Compound assignment operator that multiplies by an integer
  Box& operator/=(unsigned n);                             // Compound assignment operator that divides by an integer
};

// Less-than comparison for Box objects
inline bool Box::operator<(const Box& aBox) const
{
  return volume() < aBox.volume();
}

// Compare the volume of a Box object with a constant
inline bool Box::operator<(double aValue) const 
{
  return volume() < aValue;
}

// Function comparing a constant with volume of a Box object
inline bool operator<(double aValue, const Box& aBox)
{
  return aValue < aBox.volume();
}

// Function to add two Box objects
inline Box Box::operator+(const Box& right) const
{
  Box copy{*this};
  copy += right;
  return copy;
}

// Overloaded += operator
inline Box& Box::operator+=(const Box& right) 
{
  // New object has larger length and width, and sum of heights
  length = std::max(length, right.length);
  width  = std::max(width, right.width);
  height += right.height;
  return *this;
}

// Post-multiply an object by an integer
inline Box Box::operator*(unsigned n) const
{
  Box copy{*this};
  copy *= n;
  return copy;
}

// Overloaded *= operator
inline Box& Box::operator*=(unsigned n) 
{
  // New object has larger length and width, and sum of heights
  length *= n;
  width  *= n;
  height *= n;
  return *this;
}

// Pre-multiply an object by an integer
inline Box operator*(unsigned n, Box& box)
{
  return box * n;	// Shortest solution here is to reformulate in terms of post-multiply
}

// Post-multiply an object by an integer
inline Box Box::operator/(unsigned n) const
{
  Box copy{*this};
  copy /= n;
  return copy;
}

// Overloaded /= operator
inline Box& Box::operator/=(unsigned n) 
{
  // New object has larger length and width, and sum of heights
  length /= n;
  width  /= n;
  height /= n;
  return *this;
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