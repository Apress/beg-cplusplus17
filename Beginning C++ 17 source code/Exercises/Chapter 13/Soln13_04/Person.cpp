// Exercise 13-4 Person.cpp 
// Person class implementation

#include "Person.h"
#include <iostream>

Person::Person(size_t theAge, std::string_view theName, Gender theGender) 
  : age {theAge}, name {theName}, gender {theGender}
{
  // Instead of just initializing the members with the argument values, you could
  // validate the arguments by doing reasonableness checks. 
  // e.g. Name mustn't be empty, and age should be less than 130 say.
  // To handle a failure sensibly we really need exceptions, but we don't get to those until chapter 15. 
}

// Display details of Person object
void Person::who() const 
{
  std::cout << "\nThis is " << name << " who is " << age << " years old." << std::endl;
}

void Person::birthday()
{
	++age;
}

// Display details of Employee object
void Employee::who() const
{
  std::cout << getName() << " is a " << (isFemale()? "female": "male") << " employee aged " << getAge() << "." << std::endl;
}

// Display details of Executive object
void Executive::who() const
{
  std::cout << getName() << " is a " << (isFemale()? "female" : "male") << " executive." << std::endl;
}