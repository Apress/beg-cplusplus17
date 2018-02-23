// Overloading the << operator
#include <iostream>
#include <string_view>
#include <vector>
#include "Box.h"

int main()
{
  const std::vector<Box> boxes {Box {2.0, 2.0, 3.0}, Box {1.0, 3.0, 2.0},
                                Box {1.0, 2.0, 1.0}, Box {2.0, 3.0, 3.0}};
  const Box theBox {3.0, 1.0, 3.0};

  for (const auto& box : boxes)
    if (theBox > box) 
		std::cout << theBox << " is greater than " << box << std::endl;

  std::cout << std::endl;
  
  for (const auto& box : boxes)
    if (theBox != box && theBox.hasSameVolumeAs(box)) 
		std::cout << theBox << " is different from, but has the same volume as " << box << std::endl;

  std::cout << std::endl;  

  size_t count {0};
  for (const auto& box : boxes)
     if (box >= 10.0) ++count;
  std::cout << count << " boxes are larger than or equal to 10.0\n";

  std::cout << std::endl;
  
  for (size_t i {}; i < boxes.size() - 1; ++i)
    for (size_t j {i+1}; j < boxes.size(); ++j)
      if (boxes[i] <= boxes[j])
        std::cout << boxes[i] << " less than or equal to " << boxes[j] << std::endl;
}
