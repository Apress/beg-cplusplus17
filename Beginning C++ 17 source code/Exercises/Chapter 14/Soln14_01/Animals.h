// Exercise 14-1 Animals.h 
// Animal classes
#ifndef ANIMALS_H
#define ANIMALS_H

#include <string>
#include <string_view>

class Animal
{
private:
  std::string name;                                // Name of the animal
  unsigned weight;                                 // Weight of the animal

public:
  Animal(std::string_view theName, unsigned wt);   // Constructor
  virtual ~Animal() = default;                     // Very important: a virtual destructor!
  virtual std::string who() const;                 // Return string containing name and weight
  virtual std::string_view sound() const = 0;      // Return the sound of an animal
};

class Sheep : public Animal
{
public:
  using Animal::Animal;                            // Inherit constructor
  std::string_view sound() const override;         // Return the sound of a sheep
};

class Dog : public Animal
{
public:
  using Animal::Animal;                            // Inherit constructor
  std::string_view sound() const override;         // Return the sound of a dog
};

class Cow : public Animal
{
public:
  using Animal::Animal;                            // Inherit constructor
  std::string_view sound() const override;         // Return the sound of a cow
};

#endif