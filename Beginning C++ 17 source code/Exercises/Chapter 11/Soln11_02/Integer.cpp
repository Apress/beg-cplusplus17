// Exercise 11-2 Integer.cpp

#include <iostream>
#include "Integer.h"

// Copy constructor
Integer::Integer(const Integer& obj) : n{obj.n}
{
  std::cout << "Object created by copy constructor." << std::endl;
}

// Constructor
Integer::Integer(int m) : n{m}
{
  std::cout << "Object created." << std::endl;
}

void Integer::show() const
{
  std::cout << "Value is " << n << std::endl;
}

// Compare function
/*
int Integer::compare(Integer obj) const
{
  if(n < obj.n)
    return -1;
  else if(n==obj.n)
    return 0;
  return 1;
}
*/

// Compare function with reference parameter
// /*
int Integer::compare(const Integer& obj) const
{
  if (n < obj.n)
    return -1;
  else if (n == obj.n)
    return 0;
  else
    return 1;
}
// */