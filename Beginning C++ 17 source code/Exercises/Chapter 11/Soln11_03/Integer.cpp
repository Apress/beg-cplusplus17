// Exercise 11-3 Integer.cpp
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

Integer& Integer::add(const Integer& obj)
{ 
  n += obj.n;
  return *this;
}

Integer& Integer::subtract(const Integer& obj) 
{
  n -= obj.n;
  return *this;
}

Integer& Integer::multiply(const Integer& obj) 
{
  n *= obj.n;
  return *this;
}

void Integer::show() const
{
  std::cout << "Value is " << n << std::endl;
}

int Integer::compare(const Integer& obj) const
{
  if (n < obj.n)
    return -1;
  else if (n == obj.n)
    return 0;
  else
	return 1;
}
