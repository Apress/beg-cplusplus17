// Defining a class constructor
#include <iostream>

// Class to represent a box
class Box
{
private:
  double length {1.0};
  double width {1.0};
  double height {1.0};

public:
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
  std::cout << "Volume of Box object is " << firstBoxVolume << std::endl;

  // Box secondBox;                    // Causes a compiler error message
}
