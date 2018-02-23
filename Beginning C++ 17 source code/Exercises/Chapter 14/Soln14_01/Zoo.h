// Exercise 14-1 Animals.h 
// The Zoo class representing a collection of animals 
#ifndef ZOO_H
#define ZOO_H

#include "Animals.h"
#include <vector>
#include <memory>

using AnimalPtr = std::shared_ptr<Animal>;         // Define a type alias for convenience

class Zoo
{
private:
  std::vector<AnimalPtr> animals;      // Stores pointers to the animals

public:
  Zoo() = default;                                 // Default constructor for an empty zoo
  Zoo(const std::vector<AnimalPtr>& new_animals);  // Constructor from a vector of animals
  virtual ~Zoo() = default;                        // Add a virtual destructr to allow classes to safely derive from Zoo;
                                                   // possible examples of Zoo specializations include SafariPark, PettingZoo, ...
  void addAnimal(AnimalPtr animal);                // Add an animal to the zoo
  void showAnimals() const;                        // Output the animals and the sound they make
};

#endif