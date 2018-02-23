#ifndef BOX_H
#define BOX_H
#include <iostream>
#include <iomanip>

class Box
{
private:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  // Constructors
  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}

  Box() = default;                            // No-arg constructor

  double volume() const                       // Function to calculate the volume
  {
    return length*width*height;
  }

  // Accessors
  double getLength() const { return length; }
  double getWidth() const { return width; }
  double getHeight() const { return height; }

  // Comparison operators
  bool operator<(const Box& aBox) const { return volume() < aBox.volume(); }
  bool operator<(double value) const   { return volume() < value; }
  bool operator>(const Box& aBox) const { return volume() > aBox.volume(); }
  bool operator>(double value) const   { return volume() > value; }
  bool operator<=(const Box& aBox) const { return volume() <= aBox.volume(); }
  bool operator<=(double value) const   { return volume() <= value; }
  bool operator>=(const Box& aBox) const { return volume() >= aBox.volume(); }
  bool operator>=(double value) const   { return volume() >= value; }

  // Equality operators
  bool operator==(const Box& aBox) const
  {
    return width == aBox.width 
        && length == aBox.length
        && height == aBox.height;
  }
  bool operator!=(const Box& aBox) const
  {
    return !(*this == aBox);
  }
  
  // Function to test for equal volumes
  bool hasSameVolumeAs(const Box& aBox) const
  {
    return volume() == aBox.volume();
  }
  
  // Increment and decrement operators
  Box& operator++();            // prefix increment
  const Box operator++(int);    // postfix increment
  Box& operator--();            // prefix decrement
  const Box operator--(int);    // postfix decrement
};

// Functions comparing a constant with volume of a Box object
inline bool operator<(double value, const Box& aBox) { return value < aBox.volume(); }
inline bool operator>(double value, const Box& aBox) { return value > aBox.volume(); }
inline bool operator<=(double value, const Box& aBox) { return value >= aBox.volume(); }
inline bool operator>=(double value, const Box& aBox) { return value >= aBox.volume(); }

// The stream output operator
std::ostream& operator<<(std::ostream& stream, const Box& box)
{
  stream << "Box(" << std::setw(2) << box.getLength() << ','
    << std::setw(2) << box.getWidth() << ','
    << std::setw(2) << box.getHeight() << ')';

  return stream;
}

inline Box& Box::operator++()
{
  ++length;
  ++width;
  ++height;
  return *this;
}

inline const Box Box::operator++(int)
{
  auto copy{*this};              // Create a copy of the current object
  ++(*this);                     // Increment the current object using the prefix operator...
  return copy;                   // Return the unincremented copy
}

inline Box& Box::operator--()
{
  --length;
  --width;
  --height;
  return *this;
}

inline const Box Box::operator--(int)
{
  auto copy{*this};              // Create a copy of the current object
  --(*this);                     // Decrement the current object using the prefix operator...
  return copy;                   // Return the unincremented copy
}

#endif
