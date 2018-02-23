// Requesting the compiler to generate a default constructor
#include <iostream>

// Class to represent a box
class Box
{
private:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
  // Default constructor
  Box() = default;
  
  // Constructor
  Box(double lengthValue, double widthValue, double heightValue) 
  {
    std::cout << "Box constructor called."  << std::endl;
    length = lengthValue;
    width = widthValue;
    height = heightValue;
  }

  // Function to calculate the volume of a box
  double volume()
  {
    return length*width*height;
  }
};

int main()
{
  Box firstBox {80.0, 50.0, 40.0};               // Create a box
  double firstBoxVolume {firstBox.volume()};     // Calculate the box volume
  std::cout << "Volume of the first Box object is " << firstBoxVolume << std::endl;

  Box secondBox;                                 // Uses compiler-generated default constructor
  double secondBoxVolume{ secondBox.volume() };  // Calculate the box volume
  std::cout << "Volume of the second Box object is " << secondBoxVolume << std::endl;
}
