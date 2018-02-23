// Exercise 10-1 Using multiple files and preprocessor directives.
// We have seven files in all. 
// The file printthat.cpp contains the definition for the function print_that().
// Each of the files printthis.cpp and printthat.cpp must #include the file print.h,
// as well as its own header file: 
#include "printthat.h"
#include "print.h"

void print_that(std::string_view s) 
{
  print(s);
}