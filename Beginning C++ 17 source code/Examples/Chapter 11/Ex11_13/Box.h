#ifndef BOX_H
#define BOX_H
#include <iostream>

class Box
{
private:
  double length {1.0};
  double width {1.0};
  double height {1.0};
  static inline size_t objectCount {};              // Count of objects in existence

public:
  // Constructors
  Box(double lv, double wv, double hv);
  Box(double side);       // Constructor for a cube
  Box();                  // Default constructor
  Box(const Box& box);    // Copy constructor

  double volume() const;                            // Function to calculate the volume of a box
 
  static size_t getObjectCount() { return objectCount; }

  ~Box();                                           // Destructor
};
#endif
