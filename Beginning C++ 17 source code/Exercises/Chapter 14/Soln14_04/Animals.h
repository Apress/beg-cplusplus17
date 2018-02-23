// Exercise 14-4 Animals.h 
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
  
protected:                                         // Protected getters for use in derived classes. 
                                                   // Make the virtual to allow derived classes to override their behavior
  virtual std::string getName() const { return name; }
  virtual unsigned getWeight() const { return weight; }

public:
  Animal(std::string_view theName, unsigned wt);   // Constructor
  virtual ~Animal() = default;                     // Very important: a virtual destructor!
  
  virtual std::string who() const;                 // Return string containing name and weight
  virtual std::string_view sound() const = 0;      // Return the sound of an animal
};

class Sheep : public Animal
{
public:
  Sheep(std::string_view theName, unsigned wt);    // Constructors
  Sheep(std::string_view theName, unsigned wt, unsigned wool);
  
  std::string_view sound() const override;         // Return the sound of a sheep
  void shear();
  
protected:
  std::string getName() const override;
  unsigned getWeight() const override;
  
private:
  unsigned woolWeight;
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
  
  std::string who() const override;                // Override the behaviour of who() for Cows
  std::string_view sound() const override;         // Return the sound of a cow
};

#endif