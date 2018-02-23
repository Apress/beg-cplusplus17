// Exercise 14-1 Zoo.cpp
// Implementations of the Zoo class that stores pointers to Animals
#include "Zoo.h"
#include "Animals.h"
#include <iostream>

// Constructor from a vector of animals
Zoo::Zoo(const std::vector<AnimalPtr>& new_animals) : animals {new_animals} {}

// Add an animal to the zoo
void Zoo::addAnimal(AnimalPtr animal)
{
  animals.push_back(animal);
}

// Output the animals and the sound they make
void Zoo::showAnimals() const
{
  for (auto animal : animals)
  {
    std::cout << animal->who() << ' ' << animal->sound() << std::endl;
  }
}
