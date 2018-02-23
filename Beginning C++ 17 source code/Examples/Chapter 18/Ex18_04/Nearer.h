// A class of function objects that compare two values based on how close they are 
// to some third value that was provided to the functor at construction time.
#ifndef NEARER_H
#define NEARER_H

#include <cmath>   // For std::abs()

class Nearer
{
public:
  Nearer(int value) : n(value) {}
  bool operator()(int x, int y) const { return std::abs(x - n) < std::abs(y - n); }
private:
  int n;
};

#endif