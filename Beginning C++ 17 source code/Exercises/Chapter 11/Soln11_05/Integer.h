// Exercise 11-5 Integer.h

#ifndef INTEGER_H
#define INTEGER_H

class Integer
{
private:
  int n;
  static unsigned int count;
  
public:
  Integer(int m = 0);                      // Contructor with given value
  Integer(const Integer& obj);             // Copy constructor
  ~Integer();                              // Destructor
  int compare(const Integer& obj) const;   // Compare function with reference parameter
  int getValue() const { return n; }
  void setValue(int m) { n = m; }
  void show() const;
  
  static void printCount();
};

#endif