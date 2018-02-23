// Box.h
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
  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {};

  Box() = default;                                 // No-arg constructor

  double volume() const                            // Volume of a box
  {
    return length*width*height;
  }

  int compare(const Box& box) const
  {
    if (volume() < box.volume()) return -1;
    if (volume() == box.volume()) return 0;
    return +1;
  }

  friend std::ostream& operator<<(std::ostream& stream, const Box& box)
  {
	  stream << " Box(" << std::setw(2) << box.length << ','
		  << std::setw(2) << box.width << ','
		  << std::setw(2) << box.height << ')';
	  return stream;
  }
};

#endif
