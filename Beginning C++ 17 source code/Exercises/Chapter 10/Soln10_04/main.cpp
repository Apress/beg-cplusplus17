// Exercise 10-3 Using namespaces
// We have seven files in all. 
// The file main.cpp only needs to #include two of our three new header files,
// since all it does is call the functions print_this() and print_that():

#include "printthis.h"
#include "printthat.h"
#include "print.h"
#include <iostream>

#define DO_THIS

int main()
{
#ifdef DO_THIS
  print_this("This is a test string using print_this().");
#else
  print_that("This is a test string using print_that().");
#endif
}

// Alternative solution:
/*
#ifdef DO_THIS
  #define myprint(X) print_this(X)
#else
  #define myprint(X) print_that(X)
#endif

int main()
{
  my_print("This is a test string using print_this().");
}
*/