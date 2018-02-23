// Exercise 14-1 Exercising Zoo and Animal classes
#include "Zoo.h"
#include <cstdlib>        // For basic random number generation (std::rand() and srand())
#include <ctime>          // For std::time() (used to seed the pseudo-random number generator)
#include <iostream>

// Function to generate a random integer 0 to count-1
unsigned random(size_t count) 
{
  return static_cast<unsigned>(rand() / (RAND_MAX / count + 1));
}

int main() 
{
  std::srand(static_cast<unsigned>(std::time(0)));       // Seed random number generator

  const std::vector<std::string> dogNames { 
    "Fido", "Rover"   , "Lassie" , "Lambikins",   "Poochy",
    "Spit", "Gnasher" , "Samuel" , "Wellington" , "Patch"
  };
  const std::vector<std::string> sheepNames {
    "Bozo", "Killer", "Tasty", "Pete", "Chops",
    "Blackie", "Whitey", "Eric" , "Sean"  , "Shep"
  };
  const std::vector<std::string> cowNames {
    "Dolly", "Daisy", "Shakey", "Amy", "Dilly",
    "Dizzy", "Eleanor", "Zippy" , "Zappy", "Happy"
  };

  const unsigned minDogWt{ 1 };             // Minimum weight of a dog in pounds
  const unsigned maxDogWt{ 120 };           // Maximum weight of a dog in pounds
  const unsigned minSheepWt{ 80 };          // Minimum weight of a dog in pounds
  const unsigned maxSheepWt{ 150 };         // Maximum weight of a dog in pounds
  const unsigned minCowWt{ 800 };           // Minimum weight of a dog in pounds
  const unsigned maxCowWt{ 1500 };          // Maximum weight of a dog in pounds

  std::vector<AnimalPtr> animals;           // Stores smart pointers to animals
  size_t nAnimals {};                       // Number of animals to be created
  std::cout << "How many animals in the zoo? ";
  std::cin >> nAnimals;
  
  Zoo zoo;                  // Create an empty Zoo
  
  // Create random animals and add them to the Zoo
  for (size_t i {}; i < nAnimals; ++i)
  {
    switch (random(3)) 
    {
    case 0:                // Create a sheep
      zoo.addAnimal(std::make_shared<Sheep>(sheepNames[random(sheepNames.size())], minSheepWt + random(maxSheepWt-minSheepWt+1)));
      break;
    case 1:                // Create a dog
      zoo.addAnimal(std::make_shared<Dog>(dogNames[random(dogNames.size())], minDogWt+random(maxDogWt-minDogWt+1)));
      break;
    case 2:                // Create a cow
      zoo.addAnimal(std::make_shared<Cow>(cowNames[random(cowNames.size())], minCowWt+random(maxCowWt-minCowWt+1)));
      break;
    }
  }
  
  zoo.showAnimals();                             // Display the animals
}