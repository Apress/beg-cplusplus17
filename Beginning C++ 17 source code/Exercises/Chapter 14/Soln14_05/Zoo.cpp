// Exercise 14-5 Zoo.cpp
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

// Collect all Sheep in the Zoo using dynamic cast (the recommended way)
std::vector<SheepPtr> Zoo::herd() const
{
  std::vector<SheepPtr> sheep;
  for (auto animal : animals)
  {
    auto casted = std::dynamic_pointer_cast<Sheep>(animal);
    if (casted)
    {
      sheep.push_back(casted);
    }
  }
  return sheep;
}

/*
// Collect all Sheep in the Zoo using the typeid() operator and a static cast
// (for the sake of the exercise only)
#include <typeinfo>        // required when using typeid()

std::vector<SheepPtr> Zoo::herd() const
{
  std::vector<SheepPtr> sheep;
  for (auto animal : animals)
  {
    if (typeid(*animal) == typeid(Sheep))
    {
      sheep.push_back(std::static_pointer_cast<Sheep>(animal));
    }
  }
  return sheep;
}
*/
