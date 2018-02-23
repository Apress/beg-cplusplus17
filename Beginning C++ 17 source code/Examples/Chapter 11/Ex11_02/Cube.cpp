#include <iostream>
#include "Cube.h"

Cube::Cube(double aSide) : side{ aSide } { std::cout << "Cube constructor called." << std::endl; }

double Cube::volume()  { return side*side*side; }

bool Cube::hasLargerVolumeThan(Cube aCube) { return volume() > aCube.volume(); }
