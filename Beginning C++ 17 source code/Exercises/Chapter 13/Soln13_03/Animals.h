// Exercise 13-3 - Animals.h
// Animal class and classes derived from Animal

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

  void who() const;           // Define Lion-specific function
};

class Aardvark : public Animal
{
public:
  using Animal::Animal;                 // Inherit constructor
  
  void who() const;       // Define Aardvark-specific function
};

#endif