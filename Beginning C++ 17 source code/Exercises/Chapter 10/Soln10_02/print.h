// Exercise 10-2 Using an external variable (one that counts the amount of times print() is called).
// We have seven files in all. 
// The file print.h contains the prototype for the function print().
#ifndef PRINT_H
#define PRINT_H

#include <string_view>

// Declaration of an external variable call_count.
extern int call_count;

// Function prototype
void print(std::string_view s);

#endif