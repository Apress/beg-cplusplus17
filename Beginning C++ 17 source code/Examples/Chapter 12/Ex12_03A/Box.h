#ifndef BOX_H
#define BOX_H
#include <iostream>

/*
   We could still use the std::rel_ops operator templates for > and !=,
   but after defining >= and <=, it's not that much work to just define them all explicitly...
 */

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
};

// Functions comparing a constant with volume of a Box object
inline bool operator<(double value, const Box& aBox) { return value < aBox.volume(); }
inline bool operator>(double value, const Box& aBox) { return value > aBox.volume(); }
inline bool operator<=(double value, const Box& aBox) { return value <= aBox.volume(); }
inline bool operator>=(double value, const Box& aBox) { return value >= aBox.volume(); }

#endif
