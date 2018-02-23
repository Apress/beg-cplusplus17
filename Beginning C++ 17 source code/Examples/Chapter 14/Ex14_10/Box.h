#ifndef BOX_H
#define BOX_H

class Box
{
protected:
  double length {1.0};
  double width {1.0};
  double height {1.0};

  Box(double lv, double wv, double hv) : length {lv}, width {wv}, height {hv} {}

public:
  virtual ~Box() = default;            // Virtual destructor
  virtual double volume() const = 0;   // Function to calculate the volume
};

#endif
