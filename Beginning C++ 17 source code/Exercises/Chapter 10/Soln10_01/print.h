// Exercise 10-1 Using multiple files and preprocessor directives.
// We have seven files in all. 
// The file print.h contains the prototype for the function print().
#ifndef PRINT_H
#define PRINT_H

#include <string_view>

// Function prototype
void print(std::string_view s);

#endif