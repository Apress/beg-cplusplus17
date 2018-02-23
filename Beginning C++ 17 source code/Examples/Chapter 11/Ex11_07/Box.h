#ifndef BOX_H
#define BOX_H

class Box
{
private:
  double _length{1.0};
  double _width{1.0};
  double _height{1.0};

public:
  // Constructors
  Box() = default;
  Box(double length, double width, double height);
  
  double volume() const;      // Function to calculate the volume of a box

  // Functions to provide access to the values of member variables
  double length() const { return _length; }
  double width() const  { return _width; }
  double height() const { return _height; }

  // Functions to allow member variable values to be modified (for non-const objects only!)
  double& length() { return _length; }
  double& width()  { return _width; }
  double& height() { return _height; }
};

#endif
