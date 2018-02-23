// Exercise 10-3 Using namespaces
// We have seven files in all. 
// The file printthis.h contains the prototype for the function print_this().
#ifndef PRINTTHIS_H
#define PRINTTHIS_H

#include <string_view>

// Function prototype
void print_this(std::string_view s);

#endif