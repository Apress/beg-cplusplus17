// Using static_assert() in a class template
#include "Box.h"
#include "Array.h"
#include <iostream>
#include <iomanip>

int main()
{
  const size_t nValues {50};
  Array<double> values {nValues};                // Class constructor instance created
  try
  {
    for (size_t i {}; i < nValues; ++i)
      values[i] = static_cast<double>(i + 1);   // Member function instance created

    std::cout << "Sums of pairs of elements:";
    size_t lines {};
    for (size_t i {nValues - 1} ; i >= 0 ; i--)
      std::cout << (lines++ % 5 == 0 ? "\n" : "")
      << std::setw(5) << values[i] + values[i - 1];
  }
  catch (const std::out_of_range& ex)
  {
    std::cerr << "\nout_of_range exception object caught! " << ex.what() << std::endl;
  }

  try
  {
    const size_t nBoxes {10};
    Array<Box> boxes {nBoxes};                   // Template instance created
    for (size_t i {} ; i <= nBoxes ; ++i)        // Member instance created in loop
      std::cout << "Box volume is " << boxes[i].volume() << std::endl;
  }
  catch (const std::out_of_range& ex)
  {
    std::cerr << "\nout_of_range exception object caught! " << ex.what() << std::endl;
  }
}
