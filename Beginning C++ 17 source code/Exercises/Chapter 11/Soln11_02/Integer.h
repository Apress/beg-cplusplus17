// Exercise 11-2 Integer.h
/***************************************************************\
 This header shows two distinct ways of allowing an Integer
 to be constructed without an argument:
  1) The first is to add a default constructor. 
     The recommended way is to use the default keyword for this.
	 To make sure n is zero then, you must add a zero 
	 initialization to the declaration of the n member variable.
  2) The second is commented out and uses a default parameter
     value for the existing single-argument constructor.
\***************************************************************/

#ifndef INTEGER_H
#define INTEGER_H

// Option 1: zero-initialize n and add a default constructor
class Integer
{
private:
  int n{};

public:
  Integer() = default;                     // Zero-arg constructor
  Integer(int m);                          // Contructor with given value
  Integer(const Integer& obj);             // Copy constructor
//  int compare(Integer obj) const;        // Compare function with value parameter
  int compare(const Integer& obj) const;   // Compare function with reference parameter
  int getValue() const { return n; }
  void setValue(int m) { n = m; }
  void show() const;
};

// Option 2: use zero a default parameter value
/*
class Integer
{
private:
  int n;

public:
  Integer(int m = 0);                      // Contructor with given value
//  int compare(Integer obj) const;        // Compare function with value parameter
  int compare(const Integer& obj) const;   // Compare function with reference parameter
  int getValue() const { return n; }
  void setValue(int m) { n = m; }
  void show() const;
};
*/

#endif