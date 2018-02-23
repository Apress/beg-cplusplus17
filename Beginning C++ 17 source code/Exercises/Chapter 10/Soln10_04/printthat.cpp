// Exercise 10-3 Using namespaces
// We have seven files in all. 
// The file printthat.cpp contains the definition for the function print_that().
// Each of the files printthis.cpp and printthat.cpp must #include the file print.h,
// as well as its own header file: 
#include "printthat.h"
#include "print.h"

using print2::print;

void print_that(std::string_view s) 
{
  print(s);
}