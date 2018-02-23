// Exercise 14-6 Shapes.h 
// Shape classes
#ifndef SHAPE_H
#define SHAPE_H

#include "Point.h"

// Generic base class for shapes
class Shape
{
protected:
  Point position;                  // Position of a shape

  Shape(const Point& shapePosition) : position {shapePosition} {}

public: 
  virtual ~Shape() = default;      // Remember: always use virtual destructors for base classes!

  virtual double area() const = 0;       // Pure virtual function to compute the area of a shape
  virtual double perimeter() const = 0;  // Pure virtual function to compute the perimeter of a shape
  virtual void scale(double factor) = 0; // Pure virtual function to resize a shape by scaling

  // Regular virtual function to move a shape
  virtual void move(const Point& newPosition) { position = newPosition; };  
};

// A macro defining the mathematical constant p
#define PI 3.141592653589793238462643383279502884

// Class defining a circle
class Circle : public Shape
{
protected:
  double radius;        // Radius of a circle

public:
  Circle(const Point& center, double circleRadius) : Shape{center}, radius{circleRadius} {}

  double area() const override { return radius * radius * PI; }
  double perimeter() const override { return 2 * PI * radius; }
  
  void scale(double factor) override { radius *= factor; }
};

// Class defining a rectangle
class Rectangle : public Shape
{
protected:
  double width;        // Width of a rectangle
  double height;       // Height of a rectangle

public:
  Rectangle(const Point& center, double rectWidth, double rectHeight) 
    : Shape{center}, width{rectWidth}, height{rectHeight}  {}

  double area() const override { return width * height; }
  double perimeter() const override { return 2 * (width + height); }
 
  void scale(double factor) override { width *= factor; height *= factor; }
};


#endif