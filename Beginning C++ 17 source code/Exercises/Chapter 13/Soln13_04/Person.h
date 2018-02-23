// Exercise 13-4 Person.h
// Person class and classes derived from Person

/*
   We covered the advantages of the principle of data hiding extensively in Chapter 11.
   In practice, a common convention is to make all data members of a class private. 
   This should thus probably become your default as well. 
   Getter and setter member functions can then be added to either the public 
   or protected interface to control access and/or modifications.
   
   Alternatively, you could make the member variables of Person and Employee themselves protected.
   Often, people take this shortcut because it is somewhat less work:
   then you wouldn't need the protected getter functions.
   However, protected data is a bad idea, much for the same reason as public ones are.
   We refer to the corresponding section in Chapter 13 for a more detailed motivation.
 */

#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <string_view>

/*
  Possible alternatives for representing a gender include:
	- a Boolean value, but which is the 'true' gender?
	- a char value (say 'm' or 'f'), but then how to enforce that no other values are assigned?
	- a string ("male" / "female"), but same problem as with chars (and also excessively expensive)
  The safest, most readable solution is therefore probably an enumeration:
 */
enum class Gender { male, female };

class Person
{
private:
  size_t age {};                                     // Age in years
  std::string name;
  Gender gender{Gender::female};
  
public:
  Person() = default;                                // Default constructor
  Person(size_t theAge, std::string_view theName, Gender theGender);
  
  void who() const;                                  // Display details
  
  void birthday();

protected:  
  // Functions to allow derived classes to access to a Person's details
  size_t getAge() const    { return age; } 
  const std::string& getName() const { return name; }
  Gender getGender() const { return gender; }
  
  // Convenience functions:
  bool isMale() const { return gender == Gender::male; }
  bool isFemale() const { return gender == Gender::female; }
};

class Employee : public Person
{
private:
  long personnelNumber {};
  
public:
  Employee() = default;                          // Default constructor - necessary to define arrays
  Employee(size_t theAge, std::string_view theName, Gender theGender, long persNum)
    : Person{theAge, theName, theGender}, personnelNumber {persNum} {}
  
  void who() const;                              // Display details

protected:
  long getPersonellNumber() { return personnelNumber; }
};

class Executive: public Employee
{
public:
  Executive() = default;                         // Default constructor - necessary to define arrays
  Executive(size_t theAge, std::string_view theName, Gender theGender, long persNum)
    : Employee {theAge, theName, theGender, persNum} {}
  
  void who() const;                              // Display details
};

#endif