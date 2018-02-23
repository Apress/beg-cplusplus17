// Exercise 10-1 Using multiple files and preprocessor directives.
// We have seven files in all. 
// The file print.cpp contains the definition for the function print().
#include "print.h"
#include <iostream>

void print(std::string_view s)
{
  std::cout << s << std::endl;
}