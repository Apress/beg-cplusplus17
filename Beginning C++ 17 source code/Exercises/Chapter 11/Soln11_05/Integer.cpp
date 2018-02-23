// Exercise 11-5 Integer.cpp
/*****************************************************************\
 To implement printCount(), you first need a static member variable
 to store the object count. Every constructor should then increment
 this count, and you need to add a destructor that decrements it. 
\*****************************************************************/
#include <iostream>
#include "Integer.h"

// Initialize the static member.
// Even though its type is integral, the variable is not a constant.
// This initialisation must therefore be done outside of the class definition.
unsigned int Integer::count{};

// Constructor
Integer::Integer(int m) : n{m}
{
  ++count;
  std::cout << "Object created." << std::endl;
}

// Copy constructor
Integer::Integer(const Integer& obj) : n{obj.n}
{
  ++count;
  std::cout << "Object created by copy constructor." << std::endl;
}

// Destructor
Integer::~Integer()
{
  --count;
  std::cout << "Object deleted." << std::endl;
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

void Integer::printCount()
{
  std::cout << "There are now " << count << " Integer object(s)." << std::endl;
}