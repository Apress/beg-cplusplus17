// Exercise 11-4 Integer.cpp
/****************************************************************\
 Implementing compare() as a friend is quite simple. 
 We must declare the function as a friend in the class definition.
 We now need both objects as arguments and the code in the
 body of the function just compares the n members of the arguments.
 Both parameters are references-to-const.
 
 However, other than the need for you to exercise friend functions,
 there's no real reason for the compare() function to be a friend 
 of the Integer class: it can be implemented perfectly fine 
 using the public getValue() function as well. 
 If you want it to be a non-member function, 
 the nonFriendCompare() function given below is therefore to be
 preferred at all times over a friend function.
\****************************************************************/
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

// friend compare function
int compare(const Integer& obj1, const Integer& obj2)
{
  if (obj1.n < obj2.n)
    return -1;
  else if (obj1.n == obj2.n)
    return 0;
  else
	return 1;
}

// non-friend compare function
int nonFriendCompare(const Integer& obj1, const Integer& obj2)
{
  if (obj1.getValue() < obj2.getValue())
    return -1;
  else if (obj1.getValue() == obj2.getValue())
    return 0;
  else
	return 1;
}