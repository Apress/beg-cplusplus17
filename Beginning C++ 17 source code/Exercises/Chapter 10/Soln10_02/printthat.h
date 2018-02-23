// Exercise 10-2 Using an external variable (one that counts the amount of times print() is called).
// We have seven files in all. 
// The file printthat.h contains the prototype for the function print_that().
#ifndef PRINTTHAT_H
#define PRINTTHAT_H

#include <string_view>

// Function prototype
void print_that(std::string_view s);

#endif