// Can.h Class defining a cylindrical can of a given height and diameter
#ifndef CAN_H
#define CAN_H
#include "Vessel.h"

// A macro defining the mathematical constant p
#define PI 3.141592653589793238462643383279502884

class Can : public Vessel
{
protected:
  double diameter {1.0};
  double height {1.0};

public:
  Can(double d, double h) : diameter {d}, height {h} {}

  double volume() const override { return PI * diameter * diameter * height / 4.0; }
};
#endif
