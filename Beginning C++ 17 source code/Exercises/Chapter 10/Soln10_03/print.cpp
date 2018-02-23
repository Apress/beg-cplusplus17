// Exercise 10-3 Using namespaces
// We have seven files in all. 
// The file print.cpp contains the definition for the function print().
#include "print.h"
#include <iostream>

void print1::print(std::string_view s)
{
  std::cout << "print1: " << s << std::endl;
}

void print2::print(std::string_view s)
{
  std::cout << "print2: " << s << std::endl;
}