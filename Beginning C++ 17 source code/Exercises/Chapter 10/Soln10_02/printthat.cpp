// Exercise 10-2 Using an external variable (one that counts the amount of times print() is called).
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