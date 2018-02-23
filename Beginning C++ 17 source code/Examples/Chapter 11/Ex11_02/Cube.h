#ifndef CUBE_H
#define CUBE_H
class Cube
{
private:
  double side;

public:
  Cube(double aSide);                    // Constructor
  double volume();                       // Calculate volume of a cube
  bool hasLargerVolumeThan(Cube aCube);  // Compare volume of a cube with another
};
#endif
