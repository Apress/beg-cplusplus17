// Exercise 13-2 - Animals.h
// Animal class and classes derived from Animal

// One option is to define a public function in the derived class,
// that then hides the function of the Animal base class. 
// This is what we did for the Lion class.
// If all you want to do is to relax access specifiers,
// it is easier though to use using, as shown in the Aardvark class.

#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <string_view>

class Animal
{
private:
  std::string name;                      // Name of the animal
  int weight;                          // Weight of the animal

public:
  Animal(std::string_view name, int weight);    // Constructor
  
protected:
  void who() const;                 // Display name and weight
};

class Lion : public Animal
{
public:
  // Define Lion constructor that calls base class constructor
  Lion(std::string_view name, int weight)  
	: Animal{name, weight} {}

  void who() const;           // Define Lion-specific function
};

class Aardvark : public Animal
{
public:
  using Animal::Animal;                 // Inherit constructor
  using Animal::who;                // Inherit member function
};

#endif