// Exercise 14-6 Point.h 
// A simple class for 2-dimensional points
#ifndef POINT_H
#define POINT_H

class Point final
{
public:
  Point(double inX, double inY) : x(inX), y(inY) {}
  
  double getX() const { return x; }
  double getY() const { return y; }
  
  void setX(double inX) { x = inX; }
  void setY(double inY) { y = inY; }
  
private:
  double x;
  double y;
};

#endif