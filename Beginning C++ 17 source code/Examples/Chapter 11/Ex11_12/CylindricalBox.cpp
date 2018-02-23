#include "CylindricalBox.h"

CylindricalBox::CylindricalBox(float r, float h, std::string_view mat)
  : radius(r)
  , height(h)
  , material(mat)
{
}

double CylindricalBox::volume() const
{
  return PI * radius * radius * height;
}
