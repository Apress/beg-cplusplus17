// Exercise 2-4. Calculating the height of a tree
#include <iostream> 
#include <iomanip>
#include <cmath>

int main()
{
  const double inches_per_foot {12.0};
  const double pi {3.141592653589793238};
  const double pi_degrees {180.0};
  double d_feet {};
  double d_inches {};

  std::cout << "Enter the distance from the tree in feet and inches: ";
  std::cin >> d_feet >> d_inches;
  const double distance {d_feet + d_inches / inches_per_foot};

  double angle {};
  std::cout << "Enter the angle of the top of the tree in degrees: ";
  std::cin >> angle;
  angle *= pi / pi_degrees;                                            // Convert angle to radians 
                                                                       // (the trigoniometric functions of cmath operate with radians)
  double eye_height {};
  std::cout << "Enter your eye height from the ground in inches: ";
  std::cin >> eye_height;
  eye_height /= inches_per_foot;                                       // Convert to feet
  
  const double height {eye_height + distance * std::tan(angle)};       // Tree height in feet
  const unsigned height_feet {static_cast<unsigned>(height)};
  const unsigned height_inches {static_cast<unsigned>(std::round(inches_per_foot * (height - height_feet)))};

  std::cout << "\nThe height of the tree is "
            << height_feet << " feet "
            << height_inches << " inches.\n" << std::endl;
}