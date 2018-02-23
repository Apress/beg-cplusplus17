// Exercise 14-1 Animals.cpp
// Implementations of the Animal class and classes derived from Animal

#include "Animals.h"

// Constructor
Animal::Animal(std::string_view theName, unsigned wt) 
   : name(theName), weight(wt)
{}

// Return string describing the animal
std::string Animal::who() const
{
  return "My name is " + name + ". My weight is " + std::to_string(weight) + " lbs.";
}

// Make like a sheep
std::string_view Sheep::sound() const
{
  return "Baaaa!!";
}

// Make like a dog
std::string_view Dog::sound() const
{
  return "Woof woof!!";
}

// Make like a cow
std::string_view Cow::sound() const
{
  return "Mooooo!!";
}