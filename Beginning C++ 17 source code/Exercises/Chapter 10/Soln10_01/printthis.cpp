// Exercise 10-1 Using multiple files and preprocessor directives.
// We have seven files in all. 
// The file printthis.cpp contains the definition for the function print_this().
// Each of the files printthis.cpp and printthat.cpp must #include the file print.h,
// as well as its own header file: 
#include "printthis.h"
#include "print.h"

void print_this(std::string_view s)
{
  print(s);
}