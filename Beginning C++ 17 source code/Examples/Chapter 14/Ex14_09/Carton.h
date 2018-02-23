#ifndef CARTON_H
#define CARTON_H
#include <string>
#include <string_view>
#include "Box.h"

class Carton : public Box
{
private:
  std::string material;

public:
  // Constructor explicitly calling the base constructor
  Carton(double lv, double wv, double hv, std::string_view str)
    : Box {lv, wv, hv}, material {str}
  {}

  // Function to calculate the volume of a Carton object
  double volume() const override
  {
    double vol {(length - 0.5)*(width - 0.5)*(height - 0.5)};
    return vol > 0.0? vol : 0.0;
  }
};
#endif
