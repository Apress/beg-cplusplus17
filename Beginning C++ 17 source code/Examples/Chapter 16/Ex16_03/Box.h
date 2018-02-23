#ifndef BOX_H
#define BOX_H

class Box
{
protected:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}
//  Box() = default;

  double volume() const { return length*width*height; }
};
#endif