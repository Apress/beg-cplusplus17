#ifndef BOX_H
#define BOX_H
#include <algorithm>                        // For std::min() function template
#include "Dimension_error.h"

class Box
{
private:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv}
  {
    if (lv <= 0.0 || wv <= 0.0 || hv <= 0.0)
      throw dimension_error{ std::min( {lv, wv, hv} ) };
  }

  double volume() const { return length*width*height; }
};
#endif
