// Exercise 13-1 - Animals.h
// Animal class and classes derived from Animal

// Note: Animal, Lion, and Aardvark would typically be declared each in their 
// own header files, and then defined in three corresponding source files as well.
// This example shows that, although quite conventional, 
// this does not have to be the case; that is:
//  - file names do not have to match the name of a class; and
//  - multiple classes may be declared and defined in the same file

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
  
  void who() const;                 // Display name and weight
};

class Lion : public Animal
{
public:
  // Define Lion constructor that calls base class constructor
  Lion(std::string_view name, int weight)  
	: Animal{name, weight} {}
};

class Aardvark : public Animal
{
public:
  using Animal::Animal;         // Inherit constructor instead
};

#endif