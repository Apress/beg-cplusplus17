// Exercise 14-5 Animals.cpp
// Implementations of the Animal class and classes derived from Animal

#include "Animals.h"

// Constructor
Animal::Animal(std::string_view theName, unsigned wt) 
  : name(theName), weight(wt)
{}

// Return string describing the animal
std::string Animal::who() const
{
  return "My name is " + getName() + ". My weight is " + std::to_string(getWeight()) + " lbs.";
}

// Sheep constructors
Sheep::Sheep(std::string_view theName, unsigned wt)
  : Sheep{theName, wt, static_cast<unsigned>(0.1 * wt)}
{
}

Sheep::Sheep(std::string_view theName, unsigned wt, unsigned wool)
  : Animal{theName, wt}
  , woolWeight{wool}
{
}

// Override the behaviour of getName() and getWeight()
// for Sheep to prepend "Woolly " to their name and subtract the weight of their wool from weight.

std::string Sheep::getName() const
{
  return "Woolly " + Animal::getName();
}
unsigned Sheep::getWeight() const
{
  return Animal::getWeight() - woolWeight;
}

void Sheep::shear()
{
  woolWeight = 0;
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

// Override the behaviour of who() for Cows to hide their weight
std::string Cow::who() const
{
  return "My name is " + getName() + ".";
}  

// Make like a cow
std::string_view Cow::sound() const
{
  return "Mooooo!!";
}
