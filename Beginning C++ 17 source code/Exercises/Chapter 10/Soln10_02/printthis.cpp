// Exercise 10-2 Using an external variable (one that counts the amount of times print() is called).
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