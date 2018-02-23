// Exercise 10-3 Using namespaces
// We have seven files in all. 
// The file print.h contains the prototype for the function print().
#ifndef PRINT_H
#define PRINT_H

#include <string_view>

namespace print1
{
  // Function prototype
  void print(std::string_view s);
}

namespace print2
{
  // Function prototype
  void print(std::string_view s);
}

#endif