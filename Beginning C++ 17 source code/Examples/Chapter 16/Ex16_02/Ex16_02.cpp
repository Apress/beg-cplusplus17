// Using a class template with a non-type parameter
#include "Box.h"
#include "Array.h"
#include <iostream>
#include <iomanip>
#include <typeinfo>         // For use of typeid()

int main()
{
  try
  {
    try
    {
      const size_t size {21};                              // Number of array elements
      const int start {-10};                               // Index for first element
      const int end {start + static_cast<int>(size) - 1};  // Index for last element

      Array<double, start> values {size};                  // Define array of double values

      for (int i {start}; i <= end; ++i)                   // Initialize the elements
        values[i] = i - start + 1;

      std::cout << "Sums of pairs of elements: ";
      size_t lines {};
      for (int i {end}; i >= start; --i)
	  {
        std::cout << (lines++ % 5 == 0 ? "\n" : "")
                  << std::setw(5) << values[i] + values[i - 1];
      }
	}
    catch (const std::out_of_range& ex)
    {
      std::cerr << "\nout_of_range exception object caught! " << ex.what() << std::endl;
    }

    const int start {};
    const size_t size {11};

    Array<Box, start - 5> boxes {size};                    // Create array of Box objects

    for (int i {start - 5}; i <= start + static_cast<int>(size) - 5; ++i)
      std::cout << "Box[" << i << "] volume is " << boxes[i].volume() << std::endl;
  }
  catch (const std::exception& ex)
  {
    std::cerr << typeid(ex).name() << " exception caught in main()! "
              << ex.what() << std::endl;
  }
}

