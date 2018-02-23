#ifndef DIMENSION_ERROR_H
#define DIMENSION_ERROR_H
#include <stdexcept>                        // For derived exception classes such as std::out_of_range
#include <string>                           // For std::to_string() and the std::string type

class dimension_error : public std::out_of_range
{
private:
  double value;
public:
  explicit dimension_error(double dim)
   : std::out_of_range{"Zero or negative dimension: " + std::to_string(dim)}, value{dim} {}
  
  // Function to obtain the invalid dimension value
  double getValue() const noexcept { return value; }
};
#endif
