// Exercise 10-2 Using an external variable (one that counts the amount of times print() is called).
// We have seven files in all. 
// The file print.cpp contains the definition for the function print().
#include "print.h"
#include <iostream>

// The one definition of the variable call_count (initialized to zero).
int call_count {};			// Note: the {} is optional for definitions of global variables;
                            // if you omit the braces, the variable shall still be initialized to zero.
                            // We highly recommend you include the braces though for clarity.

void print(std::string_view s)
{
  ++call_count;
  std::cout << s << std::endl;
}