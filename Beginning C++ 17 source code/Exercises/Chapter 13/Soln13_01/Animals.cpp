// Exercise 13-1 - Animals.cpp
// Implementations of the Animal class and classes derived from Animal

#include <iostream>
#include "Animals.h"

// Constructor
Animal::Animal(std::string_view _name, int _weight) 
	: name{_name}, weight{_weight} {}

// Identify the animal
void Animal::who() const
{
  std::cout << "My name is " << name << " and I weigh " << weight << "lbs." << std::endl;
}