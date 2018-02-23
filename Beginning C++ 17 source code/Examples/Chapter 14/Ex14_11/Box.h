#ifndef BOX_H
#define BOX_H
#include "Vessel.h"

class Box : public Vessel
{
protected:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  Box() = default;
  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}

  double volume() const override { return length*width*height; }
};
#endif
